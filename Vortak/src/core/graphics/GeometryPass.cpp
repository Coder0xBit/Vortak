#include "core/graphics/GeometryPass.h"
#include "core/graphics/GraphicsDevice.h"
#include "core/graphics/Command.h"
#include "core/scene/Entity.h"
#include "core/scene/TransformComponent.h"

namespace Vortak {
    GeometryPass::GeometryPass(Vortak::GraphicsDevice* graphicsDevice) : graphicsDevice(graphicsDevice) {
        auto vertexShader = graphicsDevice->createShader("res/shader/common_vertex.glsl", ShaderType::VERTEX);
        auto fragmentShader = graphicsDevice->createShader("res/shader/common_fragment.glsl", ShaderType::FRAGMENT);

        mPipelineDescription.program = graphicsDevice->createProgram(vertexShader, fragmentShader);

        mPipelineDescription.vertexLayout = Vertex::getVertexBufferLayout();

        mPipelineDescription.blendState = {
            .enabled = false
        };

        mPipelineDescription.depthStencilState = {
            .depthTest = true,
            .depthWrite = true,
            .depthCompare = CompareOperation::Less,
        };

        mPipelineDescription.rasterizerState = {
            .cullMode = CullMode::Back,
            .frontFace = FrontFace::CounterClockwise,
            .polygonMode = PolygonMode::Fill
        };
    }

    GeometryPass::~GeometryPass() {}

    void GeometryPass::build(
        Vortak::RenderQueue<Command>& queue,
        Vortak::Scene* scene
    ) {
        if (scene->getVersion() != mLastSceneVersion) {
            mCachedCommands.clear();
            auto view = scene->getAllEntityWith<Vortak::MeshComponent, Vortak::TransformComponent>();

            for (auto& e : view) {
                Vortak::Command command;
                Entity entity = Entity(e, scene);
                auto mesh = entity.tryGetComponent<Vortak::MeshComponent>();
                auto transform = entity.tryGetComponent<Vortak::TransformComponent>();

                command.bindMesh(mesh);
                command.bindPipeline(&mPipelineDescription);
                if (transform) {
                    command.setTransform(transform->mat4());
                }

                mCachedCommands.push_back(command);
            }

            mLastSceneVersion = scene->getVersion();
        }

        for (const auto& cmd : mCachedCommands) {
            queue.push(cmd);
        }
    }
}
