#pragma once
#include "core/graphics/Program.h"

namespace Vortak {
    class OpenGLProgram : public Program {
    public:
        OpenGLProgram(Shader* vertexShader, Shader* fragmentShader);

        void bind() override;

    private :
        uint32_t mProgramId = 0;
    };
}
