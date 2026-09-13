#pragma once

#include "utils/Base.h"
#include "core/log/Logger.h"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include "core/graphics/ShaderType.h"
#include "core/graphics/VertexBufferLayout.h"

constexpr uint32_t const MAX_FRAMES_IN_FLIGHT = 2;


namespace Vortak::OpenGLUtils {
    inline GLenum getGLShaderType(Vortak::ShaderType type) {
        switch (type) {
            case Vortak::ShaderType::VERTEX:
                return GL_VERTEX_SHADER;
                break;
            case Vortak::ShaderType::FRAGMENT:
                return GL_FRAGMENT_SHADER;
                break;
            default:
                return 0;
                break;
        }
    }

    inline GLenum getGLType(Vortak::ElementType type) {
        switch (type) {
            case Vortak::ElementType::BYTE:
            case Vortak::ElementType::BYTE2:
            case Vortak::ElementType::BYTE3:
            case Vortak::ElementType::BYTE4:
                return GL_BYTE;

            case Vortak::ElementType::UBYTE:
            case Vortak::ElementType::UBYTE2:
            case Vortak::ElementType::UBYTE3:
            case Vortak::ElementType::UBYTE4:
                return GL_UNSIGNED_BYTE;

            case Vortak::ElementType::SHORT:
            case Vortak::ElementType::SHORT2:
            case Vortak::ElementType::SHORT3:
            case Vortak::ElementType::SHORT4:
                return GL_SHORT;

            case Vortak::ElementType::USHORT:
            case Vortak::ElementType::USHORT2:
            case Vortak::ElementType::USHORT3:
            case Vortak::ElementType::USHORT4:
                return GL_UNSIGNED_SHORT;

            case Vortak::ElementType::INT:
                return GL_INT;

            case Vortak::ElementType::UINT:
                return GL_UNSIGNED_INT;

            case Vortak::ElementType::FLOAT:
            case Vortak::ElementType::FLOAT2:
            case Vortak::ElementType::FLOAT3:
            case Vortak::ElementType::FLOAT4:
                return GL_FLOAT;

            case Vortak::ElementType::HALF:
            case Vortak::ElementType::HALF2:
            case Vortak::ElementType::HALF3:
            case Vortak::ElementType::HALF4:
                return GL_HALF_FLOAT;

            default:
                return GL_NONE;
        }
    }

    inline GLboolean getGLNormalized(const Vortak::Attribute& attribute) {
        if (attribute.normalized) {
            return GL_TRUE;
        }
        return GL_FALSE;
    }
}
