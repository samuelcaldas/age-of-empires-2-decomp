#include "tactical_ai_combat_subsystem_elevation_mesh_serializer.h"

static inline void serialize_offset_tables(ElevationMeshDescriptor *self, void *stream,
                                           int &index) {
    for (index = 0; index < self->m_count; index++) {
        func_00226F70(stream, &self->m_table_4[index], 4);
        func_00226F70(stream, &self->m_table_8[index], 4);
    }
}

static inline void serialize_vertex_buffer(ElevationMeshDescriptor *self, void *stream,
                                           int index) {
    int vertex_count = self->m_table_8[index];
    if (vertex_count <= 0) return;
    unsigned int byte_count = static_cast<unsigned int>(vertex_count) << 3;
    func_00226F70(stream, self->m_table_0[index], static_cast<int>(byte_count));
}

static inline void serialize_vertex_buffers(ElevationMeshDescriptor *self, void *stream,
                                            int &index) {
    for (index = 0; index < self->m_count; index++) {
        serialize_vertex_buffer(self, stream, index);
    }
}

void func_00328020(ElevationMeshDescriptor *self, void *stream) {
    int index;
    func_00226F70(stream, &self->m_count, 4);
    serialize_offset_tables(self, stream, index);
    serialize_vertex_buffers(self, stream, index);
}
