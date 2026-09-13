#include "core/graphics/opengl/OpenGLVertexBuffer.h"
#include "core/graphics/opengl/OpenGLUtils.h"

namespace Vortak {
    OpenGLVertexBuffer::OpenGLVertexBuffer(
        VertexBufferLayout bufferLayout
    ) : VertexBuffer(std::move(bufferLayout)) {
        glGenVertexArrays(1, &mVertexArrayId);
        glGenBuffers(1, &mVertexBufferId);
    }

    void OpenGLVertexBuffer::bind() {
        glBindVertexArray(mVertexArrayId);
        glBindBuffer(GL_ARRAY_BUFFER, mVertexBufferId);
    }

    void OpenGLVertexBuffer::unBind() {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void OpenGLVertexBuffer::setBuffer(const std::vector<Vortak::Vertex>& vertices) {
        bind();
        mSize = vertices.size();
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);

        auto attributes = bufferLayout.getAttributes();

        uint32_t offset = 0;

        for (auto& attribute : attributes) {
            uint32_t count = getElementCount(attribute.type);
            GLenum type = OpenGLUtils::getGLType(attribute.type);
            GLboolean normalized = OpenGLUtils::getGLNormalized(attribute);

            glVertexAttribPointer(
                attribute.location,
                static_cast<GLsizei>(count),
                type,
                normalized,
                static_cast<GLsizei>(bufferLayout.getStride()),
                reinterpret_cast<void*>(offset)
            );

            glEnableVertexAttribArray(attribute.location);

            offset += getElementSize(attribute.type);
        }
        unBind();
    }

    uint32_t OpenGLVertexBuffer::getSize() {
        return mSize;
    }
}
