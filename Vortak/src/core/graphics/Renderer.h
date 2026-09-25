#pragma once

#include "utils/Base.h"
#include "core/graphics/Command.h"
#include "core/graphics/RenderQueue.h"
#include "core/graphics/SwapChain.h"
#include "core/graphics/Backend.h"
#include "core/Camera.h"
#include "core/graphics/GraphicsDevice.h"
#include "core/graphics/BufferManager.h"
#include "core/scene/Scene.h"
#include "core/graphics/GeometryPass.h" // Added GeometryPass

namespace Vortak {
    class Renderer {
    public:
        struct BuilderDetails {
            Backend backend = Vulkan;
            GraphicsDevice* device = nullptr;
            Window* window = nullptr;
        };

        class Builder : public utils::PrivateImplementation<BuilderDetails> {
            friend class Renderer;
            friend class VulkanRenderer;

        public:
            Builder() noexcept;

            Builder(Builder const& rhs) noexcept;

            Builder(Builder&& rhs) noexcept;

            ~Builder() noexcept;

            Builder& operator=(Builder const& rhs) noexcept;

            Builder& operator=(Builder&& rhs) noexcept;

            Builder& backend(Backend backend) noexcept;

            Builder& device(GraphicsDevice* platform) noexcept;

            Builder& window(Window* window) noexcept;

            std::unique_ptr<Renderer> build() const noexcept;
        };

        Renderer() = delete;

        Renderer(const Builder& builder) noexcept;

        Renderer(Renderer&& rhs) = delete;

        Renderer(Renderer& rhs) = delete;

        auto& operator =(Renderer&& rhs) = delete;

        auto& operator =(Renderer& rhs) = delete;

        virtual bool beginFrame();

        virtual void render(Vortak::Camera* camera, Vortak::Scene* scene);

        virtual void endFrame();

        virtual ~Renderer();

        virtual SwapChain* getSwapChain() const;

    private:
        friend class Builder;

    protected :
        Vortak::RenderQueue<Command> mRenderQueue;
        std::unique_ptr<GeometryPass> mGeometryPass; // Store geometry pass internally
        GraphicsDevice* mGraphicsDevice = nullptr;
        std::unique_ptr<BufferManager> mBufferManager = nullptr;
        Window* mWindow = nullptr;
        Backend mBackend = Vulkan;

        Shader* mVertexShader = nullptr;
        Shader* mFragmentShader = nullptr;
    };
}
