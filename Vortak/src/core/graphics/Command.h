#pragma once

#include "utils/Base.h"
#include "core/scene/MeshComponent.h"
#include "core/graphics/PipelineDescription.h"
#include <glm/glm.hpp>

namespace Vortak {
    class Command {
    public :
        Command() = default;

        ~Command() = default;

        void bindMesh(MeshComponent* meshComponent) { mMeshComponent = meshComponent; }

        void bindPipeline(PipelineDescription* pipelineDescription) { mPipelineDescription = pipelineDescription; }

        void setTransform(const glm::mat4& transform) { mTransform = transform; }

        void drawIndexed(uint32_t indexCount, uint32_t instanceCount, uint32_t firstIndex,
                         int32_t vertexOffset, uint32_t firstInstance) {
            // Store draw call arguments if needed
        }

        MeshComponent* getMesh() const { return mMeshComponent; }
        PipelineDescription* getPipeline() const { return mPipelineDescription; }
        const glm::mat4& getTransform() const { return mTransform; }

    protected:
        MeshComponent* mMeshComponent = nullptr;
        PipelineDescription* mPipelineDescription = nullptr;
        glm::mat4 mTransform{1.0f};
    };
}
