#include "core/graphics/GeometryPass.h"
#include "core/graphics/GraphicsDevice.h"
#include "core/graphics/Command.h"
#include "core/scene/Entity.h"

namespace Vortak {
    void GeometryPass::build(
        Vortak::RenderQueue<Command>& queue,
        Vortak::Scene* scene,
        Vortak::GraphicsDevice* graphicsDevice
    ) {
        if (!mInitialized) {
            auto vertexShader = graphicsDevice->createShader("res/shader/common_vertex.glsl", ShaderType::VERTEX);
            auto fragmentShader = graphicsDevice->createShader("res/shader/common_fragment.glsl", ShaderType::FRAGMENT);
            
            mCachedPipeline.program = graphicsDevice->createProgram(vertexShader, fragmentShader);

            mCachedPipeline.vertexLayout = Vertex::getVertexBufferLayout();

            mCachedPipeline.blendState = {
                .enabled = false
            };

            mCachedPipeline.depthStencilState = {
                .depthTest = true,
                .depthWrite = true,
                .depthCompare = CompareOperation::Less,
            };

            mCachedPipeline.rasterizerState = {
                .cullMode = CullMode::Back,
                .frontFace = FrontFace::CounterClockwise,
                .polygonMode = PolygonMode::Fill
            };

            mInitialized = true;
        }

        if (scene->getVersion() != mLastSceneVersion) {
            mCachedCommands.clear();
            auto view = scene->getAllEntityWith<Vortak::MeshComponent>();

            for (auto& handle : view) {
                Vortak::Command command;
                Entity e = Entity(handle, scene);
                auto mesh = e.tryGetComponent<Vortak::MeshComponent>();

                command.bindMesh(mesh);
                command.bindPipeline(&mCachedPipeline);

                mCachedCommands.push_back(command);
            }

            mLastSceneVersion = scene->getVersion();
        }

        for (const auto& cmd : mCachedCommands) {
            queue.push(cmd);
        }
    }
}
