#pragma once
#include "core/graphics/Command.h"
#include "core/graphics/RenderQueue.h"
#include "core/scene/Scene.h"

namespace Vortak {
    class RenderPass {
    public :
        RenderPass() = default;

        RenderPass(const RenderPass& renderPass) = delete;

        RenderPass& operator=(const RenderPass& renderPass) = delete;

        RenderPass(RenderPass&& renderPass) = delete;

        RenderPass& operator=(RenderPass&& renderPass) = delete;

        virtual ~RenderPass() = default;

        virtual void build(
            Vortak::RenderQueue<Command>& queue,
            Vortak::Scene* scene
        ) = 0;
    };
}
