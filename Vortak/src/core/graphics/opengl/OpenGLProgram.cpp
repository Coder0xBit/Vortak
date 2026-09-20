#include "core/graphics/opengl/OpenGLProgram.h"
#include "core/graphics/opengl/OpenGLShader.h"


namespace Vortak {
    OpenGLProgram::OpenGLProgram(
        Shader* vertexShader,
        Shader* fragmentShader
    ) : Program(vertexShader, fragmentShader) {
        auto glVertexShader = dynamic_cast<OpenGLShader*>(this->vertexShader);
        auto glFragmentShader = dynamic_cast<OpenGLShader*>(this->fragmentShader);

        mProgramId = glCreateProgram();
        glAttachShader(mProgramId, glVertexShader->getShaderId());
        glAttachShader(mProgramId, glFragmentShader->getShaderId());
        glLinkProgram(mProgramId);
    }

    void OpenGLProgram::bind() {
        glUseProgram(mProgramId);
    }
}
