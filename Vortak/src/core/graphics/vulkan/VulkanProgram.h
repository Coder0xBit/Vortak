#pragma once
#include "core/graphics/Program.h"

namespace Vortak {
    class VulkanProgram : public Program {
    public:
        VulkanProgram(Shader* vertexShader, Shader* fragmentShader);

        void bind() override;
    };
}
