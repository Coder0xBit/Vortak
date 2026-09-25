#include "core/graphics/Renderer.h"
#include "core/graphics/vulkan/VulkanRenderer.h"

namespace Vortak {
    Renderer::Builder::Builder() noexcept = default;

    Renderer::Builder::Builder(Builder const& rhs) noexcept = default;

    Renderer::Builder::Builder(Builder&& rhs) noexcept = default;

    Renderer::Builder::~Builder() noexcept = default;

    Renderer::Builder& Renderer::Builder::operator=(Builder const& rhs) noexcept = default;

    Renderer::Builder& Renderer::Builder::operator=(Builder&& rhs) noexcept = default;

    Renderer::Builder& Renderer::Builder::backend(const Backend backend) noexcept {
        mImpl->backend = backend;
        return *this;
    }

    Renderer::Builder& Renderer::Builder::device(GraphicsDevice* device) noexcept {
        mImpl->device = device;
        return *this;
    }

    Renderer::Builder& Renderer::Builder::window(Window* window) noexcept {
        mImpl->window = window;
        return *this;
    }

    std::unique_ptr<Renderer> Renderer::Builder::build() const noexcept {
        return std::make_unique<Renderer>(*this);
    }

    Renderer::Renderer(const Builder& builder) noexcept {
        mGraphicsDevice = builder.mImpl->device;
        mWindow = builder.mImpl->window;
        mBackend = builder.mImpl->backend;

        mBufferManager = std::make_unique<BufferManager>(mGraphicsDevice, mBackend);
        mGeometryPass = std::make_unique<GeometryPass>(mGraphicsDevice);
    }

    bool Renderer::beginFrame() { return true; }


    void Renderer::render(Vortak::Camera* camera, Vortak::Scene* scene) {
        mGeometryPass->build(mRenderQueue, scene);

        Command cmd;
        while (mRenderQueue.tryPop(cmd)) {
            auto mesh = cmd.getMesh();
            auto pipeline = cmd.getPipeline();

            if (!mesh) continue;

            mGraphicsDevice->bindPipeline(pipeline);

            for (auto& subMeshes : mesh->subMeshes) {
                auto meshKey = MeshKey(mesh->modelHandle, subMeshes.meshIndex);
                if (auto meshBuffer = mBufferManager->getMesh(meshKey)) {
                    mGraphicsDevice->bindMesh(meshBuffer);

                    uint32_t indexCount = meshBuffer->indexBuffer->getCount();
                    mGraphicsDevice->drawIndexed(indexCount, 1, 0, 0, 0);
                }
            }
        }
    }
    void Renderer::endFrame() {}

    SwapChain* Renderer::getSwapChain() const { return nullptr; }

    Renderer::~Renderer() {}
}
