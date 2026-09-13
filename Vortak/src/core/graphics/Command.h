#pragma once

#include "utils/Base.h"
#include "core/scene/MeshComponent.h"
#include "core/graphics/PipelineDescription.h"

namespace Vortak {
    class Command {
    public :
        Command() = default;

        ~Command() = default;

        void bindMesh(MeshComponent* meshComponent) { mMeshComponent = meshComponent; }

        void bindPipeline(PipelineDescription* pipelineDescription) { mPipelineDescription = pipelineDescription; }

        void drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                         int32_t vertexOffset, uint32_t firstInstance) {
            // Store draw call arguments if needed
        }

        MeshComponent* getMesh() const { return mMeshComponent; }
        PipelineDescription* getPipeline() const { return mPipelineDescription; }

    protected:
        MeshComponent* mMeshComponent = nullptr;
        PipelineDescription* mPipelineDescription = nullptr;
    };
}
