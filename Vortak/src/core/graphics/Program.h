#pragma once
#include "utils/Base.h"
#include "core/graphics/Shader.h"

namespace Vortak {
    class Program {
    public :
        Program(Shader* vertexShader, Shader* fragmentShader);

        virtual void bind() = 0;

        virtual ~Program();

    protected:
        Shader* vertexShader = nullptr;
        Shader* fragmentShader = nullptr;
    };
}
