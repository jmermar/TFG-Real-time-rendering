#include "MeshLoader.hpp"
#include <tiny_obj_loader.h>
#include <iostream>

namespace MeshLoader {
    Vertex getVertex(tinyobj::attrib_t attrib, tinyobj::index_t index) {
        Vertex v;
        v.pos.x = attrib.vertices[index.vertex_index * 3 + 0];
        v.pos.y = attrib.vertices[index.vertex_index * 3 + 1];
        v.pos.z = attrib.vertices[index.vertex_index * 3 + 2];

        if (index.texcoord_index >= 0) {
            v.uv.x = attrib.texcoords[index.texcoord_index * 2 + 0];
            v.uv.y = attrib.texcoords[index.texcoord_index * 2 + 1];
        } else {
            v.uv = glm::vec2(0);
        }

        v.norm.x = attrib.normals[index.normal_index * 3 + 0];
        v.norm.y = attrib.normals[index.normal_index * 3 + 1];
        v.norm.z = attrib.normals[index.normal_index * 3 + 2];

        return v;
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
            for (int i = 0; i < shapes[s].mesh.num_face_vertices.size(); i++) {
                Vertex v1 = getVertex(attrib, shapes[s].mesh.indices[i * 3 + 0]);
                Vertex v2 = getVertex(attrib, shapes[s].mesh.indices[i * 3 + 1]);
                Vertex v3 = getVertex(attrib, shapes[s].mesh.indices[i * 3 + 2]);

                // http://www.opengl-tutorial.org/intermediate-tutorials/tutorial-13-normal-mapping/#computing-the-tangents-and-bitangents
                glm::vec3 deltaPos1 = v3.pos - v1.pos;
                glm::vec3 deltaPos2 = v2.pos - v1.pos;
                glm::vec2 deltaUV1 = v3.uv - v1.uv;
                glm::vec2 deltaUV2 = v2.uv - v1.uv;

                //v1.norm = v2.norm = v3.norm = glm::normalize(glm::cross(deltaPos2, deltaPos1));

                glm::vec3 tangent = (deltaPos1 * deltaUV2.y   - deltaPos2 * deltaUV1.y);
                glm::vec3 bitangent = (deltaPos2 * deltaUV1.x   - deltaPos1 * deltaUV2.x);

                v1.tangent = v2.tangent = v3.tangent = tangent;
                v1.bitangent = v2.bitangent = v3.bitangent = bitangent;

                vertices.push_back(v1);
                vertices.push_back(v2);
                vertices.push_back(v3);


                indices.push_back(i * 3 + 0);
                indices.push_back(i * 3 + 1);
                indices.push_back(i * 3 + 2);
            }
        }
    }
};