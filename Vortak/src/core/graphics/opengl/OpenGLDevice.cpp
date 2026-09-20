#include <glad/gl.h>
#include "core/graphics/opengl/OpenGLDevice.h"
#include "core/graphics/opengl/OpenGLShader.h"
#include "core/graphics/opengl/OpenGLProgram.h"

#include "core/resource/ResourceManager.h"

namespace Vortak {
    OpenGLDevice::OpenGLDevice() {
        if (!gladLoadGL(glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }
    }

    void OpenGLDevice::initialize() {}

    void OpenGLDevice::shutDown() {}

    SwapChain* OpenGLDevice::createSwapChain(Window* window) {
        return nullptr;
    }

    Shader* OpenGLDevice::createShader(const std::filesystem::path& path, ShaderType shaderType) {
        auto shaderProgram = ResourceManager::get().load<ShaderProgram>(path.string());
        auto* shader = Memory::Allocate<OpenGLShader>(this, shaderProgram, shaderType);
        return shader;
    }

    void OpenGLDevice::bindPipeline(Vortak::PipelineDescription* pipelineDescription) {
        if (pipelineDescription->program) {
            pipelineDescription->program->bind();
        }
    }

    Program* OpenGLDevice::createProgram(Shader* vertexShader, Shader* fragmentShader) {
        return Memory::Allocate<OpenGLProgram>(vertexShader, fragmentShader);
    }

    void OpenGLDevice::drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset, uint32_t firstInstance) {
        // Simplest implementation for drawing in OpenGL
        glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, (void*)(firstIndex * sizeof(uint32_t)));
    }

    OpenGLDevice::~OpenGLDevice() {}
}
