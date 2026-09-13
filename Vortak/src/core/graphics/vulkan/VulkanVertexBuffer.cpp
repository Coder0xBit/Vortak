#include <utility>

#include "core/graphics/vulkan/VulkanVertexBuffer.h"

namespace Vortak {
    VulkanVertexBuffer::VulkanVertexBuffer(
        GraphicsDevice* graphicsDevice,
        VertexBufferLayout bufferLayout
    ) : VertexBuffer(std::move(bufferLayout)) {
        mVulkanDevice = static_cast<VulkanDevice*>(graphicsDevice);
        mBuffer = std::make_unique<VulkanBuffer>(mVulkanDevice);
    }

    VulkanVertexBuffer::~VulkanVertexBuffer() {
    }

    void VulkanVertexBuffer::bind() {
    }

    void VulkanVertexBuffer::unBind() {
    }

    void VulkanVertexBuffer::setBuffer(const std::vector<Vortak::Vertex>& vertices) {
        mBuffer->create(vertices.size(), sizeof(Vortak::Vertex),
                        vk::BufferUsageFlagBits::eVertexBuffer);
        mBuffer->allocate(mBufferProperties);
        mBuffer->map();
        mBuffer->write((void*) (vertices.data()));
    }
}
