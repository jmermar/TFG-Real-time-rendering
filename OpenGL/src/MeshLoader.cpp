#include "MeshLoader.hpp"
#include <tiny_obj_loader.h>
#include <iostream>

namespace MeshLoader {
    void loadMesh(string name, vector<Vertex>& vertices, vector<GLuint>& indices) {
        vertices.clear();
        indices.clear();
        tinyobj::ObjReaderConfig reader_config;
        reader_config.mtl_search_path = "res/models/";
        reader_config.triangulate = true;

        tinyobj::ObjReader reader;

        if (!reader.ParseFromFile(name, reader_config)) {
            cerr << "Error cargando fichero OBJ(" << name << "): " << reader.Error();
            exit(1);
        }

        if (!reader.Warning().empty()) {
            cout << "Warning cargando fichero OBJ (" << name << "): " << reader.Warning() << endl;
        }

        auto& attrib = reader.GetAttrib();
        auto& shapes = reader.GetShapes();
        auto& materials = reader.GetMaterials();

        // Iteramos las figuras
        for(int s = 0; s < shapes.size(); s++) {
            // Iteramos las caras
            for (int i = 0; i < shapes[s].mesh.indices.size(); i++) {

                Vertex v;
                v.pos.x = attrib.vertices[shapes[s].mesh.indices[i].vertex_index * 3 + 0];
                v.pos.y = attrib.vertices[shapes[s].mesh.indices[i].vertex_index * 3 + 1];
                v.pos.z = attrib.vertices[shapes[s].mesh.indices[i].vertex_index * 3 + 2];

                v.uv.x = attrib.texcoords[shapes[s].mesh.indices[i].texcoord_index * 2 + 0];
                v.uv.y = attrib.texcoords[shapes[s].mesh.indices[i].texcoord_index * 2 + 1];

                v.norm.x = attrib.normals[shapes[s].mesh.indices[i].normal_index * 3 + 0];
                v.norm.y = attrib.normals[shapes[s].mesh.indices[i].normal_index * 3 + 1];
                v.norm.z = attrib.normals[shapes[s].mesh.indices[i].normal_index * 3 + 2];

                vertices.push_back(v);

                indices.push_back(i);
            }
        }
    }
};