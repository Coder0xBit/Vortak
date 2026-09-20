#pragma once
#include "core/graphics/opengl/OpenGLUtils.h"
#include "core/graphics/Shader.h"

namespace Vortak {
    class OpenGLShader : public Shader {
    public:
        OpenGLShader(GraphicsDevice* graphicsDevice, ShaderProgram* shaderProgram, ShaderType shaderType);

        ~OpenGLShader() override;

        void compile() override;

        uint32_t getShaderId() const { return mShaderID; }

    private :
        uint32_t mShaderID = 0;
    };
}
