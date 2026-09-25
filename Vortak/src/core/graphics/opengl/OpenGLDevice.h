#pragma once
#include "core/graphics/GraphicsDevice.h"
#include "core/graphics/ShaderType.h"

namespace Vortak {

    class OpenGLDevice : public GraphicsDevice {
    public:
        OpenGLDevice();

        void initialize() override;

        void shutDown() override;

        SwapChain* createSwapChain(Window* window) override;

        Shader* createShader(const std::filesystem::path& path, ShaderType shaderType) override;

        Program* createProgram(Shader* vertexShader, Shader* fragmentShader) override;

        void bindPipeline(Vortak::PipelineDescription* pipelineDescription) override;

        void bindMesh(const Vortak::MeshBuffer* meshBuffer) override;

        void drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex, int32_t vertexOffset,
                         uint32_t firstInstance) override;

        ~OpenGLDevice() override;
    };
}
