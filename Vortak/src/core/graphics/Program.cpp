#include "core/graphics/Program.h"

namespace Vortak {
    Program::Program(Shader* vertexShader, Shader* fragmentShader) :
        vertexShader(vertexShader), fragmentShader(fragmentShader) {}


    Program::~Program() {
        Memory::Deallocate(vertexShader);
        Memory::Deallocate(fragmentShader);
    }
}
