#pragma once
#include "core/graphics/RenderPass.h"
#include "core/scene/MeshComponent.h"
#include <vector>

namespace Vortak {
    class GeometryPass : public RenderPass {
    public:
        GeometryPass() = default;

        void build(
            Vortak::RenderQueue<Command>& queue,
            Vortak::Scene* scene,
            Vortak::GraphicsDevice* graphicsDevice
        ) override;

    private:
        bool mInitialized = false;
        PipelineDescription mCachedPipeline;
        std::vector<Vortak::Command> mCachedCommands;
        uint32_t mLastSceneVersion = 0;
    };
}
