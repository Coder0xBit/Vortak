#include "core/graphics/vulkan/VulkanProgram.h"
#include "core/graphics/vulkan/VulkanShader.h"

namespace Vortak {
    VulkanProgram::VulkanProgram(Shader* vertexShader, Shader* fragmentShader)
        : Program(vertexShader, fragmentShader) {}

    void VulkanProgram::bind() {
        // TODO: Vulkan program binding logic goes here or inside pipeline creation phase.
    }
}
