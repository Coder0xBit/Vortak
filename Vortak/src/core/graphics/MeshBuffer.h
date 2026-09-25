#pragma once

#include "utils/Base.h"
#include "core/graphics/VertexBuffer.h"
#include "core/graphics/IndexBuffer.h"

namespace Vortak {
    struct MeshBuffer {
        std::unique_ptr<VertexBuffer> vertexBuffer;
        std::unique_ptr<IndexBuffer> indexBuffer;
    };
}
