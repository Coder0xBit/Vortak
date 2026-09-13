#include "core/graphics/vulkan/VulkanIndexBuffer.h"

namespace Vortak {
    VulkanIndexBuffer::VulkanIndexBuffer(GraphicsDevice* graphicsDevice) {
        mVulkanDevice = static_cast<VulkanDevice*>(graphicsDevice);
        mBuffer = std::make_unique<VulkanBuffer>(mVulkanDevice);
    }

    VulkanIndexBuffer::~VulkanIndexBuffer() {
    }

    void VulkanIndexBuffer::bind() {
    }

    void VulkanIndexBuffer::unBind() {
    }

    void VulkanIndexBuffer::setBuffer(const std::vector<uint32_t>& indices) {
        mBuffer->create(indices.size(), sizeof(uint32_t),
                        vk::BufferUsageFlagBits::eIndexBuffer);
        mBuffer->allocate(mBufferProperties);
        mBuffer->map();
        mBuffer->write((void*) (indices.data()));
    }
}
