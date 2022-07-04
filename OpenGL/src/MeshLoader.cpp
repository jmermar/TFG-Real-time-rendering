#include "MeshLoader.hpp"
#include <tiny_obj_loader.h>
#include <iostream>

namespace MeshLoader {
    inline void getVertex(Vertex& v, const tinyobj::attrib_t& attrib, const tinyobj::index_t& index) {
        v.pos.x = attrib.vertices[index.vertex_index * 3 + 0];
        v.pos.y = attrib.vertices[index.vertex_index * 3 + 1];
        v.pos.z = attrib.vertices[index.vertex_index * 3 + 2];

        if (index.texcoord_index >= 0) {
            v.uv.x = attrib.texcoords[index.texcoord_index * 2 + 0];
            v.uv.y = -attrib.texcoords[index.texcoord_index * 2 + 1];
        }

        v.norm.x = attrib.normals[index.normal_index * 3 + 0];
        v.norm.y = attrib.normals[index.normal_index * 3 + 1];
        v.norm.z = attrib.normals[index.normal_index * 3 + 2];
}

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
            int idx = 0;
            vertices.reserve(vertices.size() + shapes[s].mesh.num_face_vertices.size() * 3);
            indices.reserve(indices.size() + shapes[s].mesh.num_face_vertices.size() * 3);
            for (int i = 0; i < shapes[s].mesh.num_face_vertices.size(); i++) {
                Vertex v1;
                getVertex(v1, attrib, shapes[s].mesh.indices[idx + 0]);
                Vertex v2;
                getVertex(v2, attrib, shapes[s].mesh.indices[idx + 1]);
                Vertex v3;
                getVertex(v3, attrib, shapes[s].mesh.indices[idx + 2]);

                vertices.push_back(v1);
                vertices.push_back(v2);
                vertices.push_back(v3);


                indices.push_back(idx + 0);
                indices.push_back(idx + 1);
                indices.push_back(idx + 2);

                idx += 3;
            }
        }
    }
};