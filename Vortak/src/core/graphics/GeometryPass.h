#pragma once
#include "core/graphics/RenderPass.h"
#include "core/scene/MeshComponent.h"
#include <vector>

namespace Vortak {
    class GeometryPass : public RenderPass {
    public:
        explicit GeometryPass(Vortak::GraphicsDevice* graphicsDevice);

        GeometryPass(const GeometryPass&) = delete;

        GeometryPass& operator=(const GeometryPass&) = delete;

        GeometryPass(GeometryPass&&) = delete;

        GeometryPass& operator=(GeometryPass&&) = delete;

        ~GeometryPass() override;

        void build(
            Vortak::RenderQueue<Command>& queue,
            Vortak::Scene* scene
        ) override;

    private:
        bool mInitialized = false;
        Vortak::GraphicsDevice* graphicsDevice = nullptr;
        PipelineDescription mPipelineDescription;
        std::vector<Vortak::Command> mCachedCommands;
        uint32_t mLastSceneVersion = 0;
    };
}
