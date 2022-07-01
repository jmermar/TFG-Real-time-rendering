#include <Mesh.hpp>

#include <tiny_obj_loader.h>
#include <iostream>

Vertex loadVertex(const tinyobj::attrib_t& attr, tinyobj::index_t idx) {
    Vertex v;

    v.pos.x = attr.vertices[3 * idx.vertex_index];
    v.pos.y = attr.vertices[3 * idx.vertex_index + 1];
    v.pos.z = attr.vertices[3 * idx.vertex_index + 2];

    if (idx.texcoord_index >= 0) {
        v.uv.x = attr.texcoords[2 * idx.texcoord_index];
        v.uv.y = 1 - attr.texcoords[2 * idx.texcoord_index + 1];
    }

    return v;
}

Mesh loadMesh(string file, bool ccw) {
    Mesh mesh;

    tinyobj::ObjReaderConfig reader_config;
    reader_config.mtl_search_path = "res/";
    reader_config.triangulate = true;

    tinyobj::ObjReader reader;

    if (!reader.ParseFromFile(file, reader_config)) {
        cerr << "Error cargando fichero OBJ(" << file << "): " << reader.Error();
        exit(1);
    }

    if (!reader.Warning().empty()) {
        cout << "Warning cargando fichero OBJ (" << file << "): " << reader.Warning() << endl;
    }


    auto& attrib = reader.GetAttrib();
    auto& shapes = reader.GetShapes();
    auto& materials = reader.GetMaterials();

    // Iteramos las figuras
    for(int s = 0; s < shapes.size(); s++) {
        int index_offset = 0;
        // Iteramos las caras
        for (int f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            Triangle face;
        
            if (ccw) {
                face.a = loadVertex(attrib, shapes[s].mesh.indices[index_offset + 0]);
                face.c = loadVertex(attrib, shapes[s].mesh.indices[index_offset + 1]);
                face.b = loadVertex(attrib, shapes[s].mesh.indices[index_offset + 2]);

            } else {
                face.a = loadVertex(attrib, shapes[s].mesh.indices[index_offset + 0]);
                face.b = loadVertex(attrib, shapes[s].mesh.indices[index_offset + 1]);
                face.c = loadVertex(attrib, shapes[s].mesh.indices[index_offset + 2]);

            }
            

            mesh.triangles.push_back(face);

            index_offset += 3;
        }
    }

    return mesh;
}