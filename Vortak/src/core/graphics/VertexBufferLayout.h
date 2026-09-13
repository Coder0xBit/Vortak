#pragma once
#include "utils/Base.h"

namespace Vortak {
    enum class ElementType : uint8_t {
        BYTE, BYTE2, BYTE3, BYTE4, UBYTE, UBYTE2, UBYTE3, UBYTE4, SHORT, SHORT2, SHORT3, SHORT4, USHORT, USHORT2,
        USHORT3, USHORT4, INT, UINT, FLOAT, FLOAT2, FLOAT3, FLOAT4, HALF, HALF2, HALF3, HALF4,
    };

    enum class VertexAttribute : uint8_t {
        POSITON, COLOR, NORMAL, UV
    };

    struct Attribute {
        uint32_t location = 0;
        VertexAttribute vertexAttribute = VertexAttribute::POSITON;
        ElementType type = ElementType::FLOAT3;
        bool normalized = false;
    };

    static constexpr uint32_t getElementCount(ElementType type) {
        switch (type) {
            case ElementType::FLOAT:
                return 1;
                break;

            case ElementType::FLOAT2:
                return 2;
                break;

            case ElementType::FLOAT3:
                return 3;
                break;

            case ElementType::FLOAT4:
                return 4;
                break;

            default:
                return 0;
                break;
        }
    }

    static constexpr uint32_t getElementSize(ElementType type) {
        switch (type) {
            case ElementType::BYTE:
                return sizeof(int8_t);
            case ElementType::BYTE2:
                return sizeof(int8_t) * 2;
            case ElementType::BYTE3:
                return sizeof(int8_t) * 3;
            case ElementType::BYTE4:
                return sizeof(int8_t) * 4;

            case ElementType::UBYTE:
                return sizeof(uint8_t);
            case ElementType::UBYTE2:
                return sizeof(uint8_t) * 2;
            case ElementType::UBYTE3:
                return sizeof(uint8_t) * 3;
            case ElementType::UBYTE4:
                return sizeof(uint8_t) * 4;

            case ElementType::SHORT:
                return sizeof(int16_t);
            case ElementType::SHORT2:
                return sizeof(int16_t) * 2;
            case ElementType::SHORT3:
                return sizeof(int16_t) * 3;
            case ElementType::SHORT4:
                return sizeof(int16_t) * 4;

            case ElementType::USHORT:
                return sizeof(uint16_t);
            case ElementType::USHORT2:
                return sizeof(uint16_t) * 2;
            case ElementType::USHORT3:
                return sizeof(uint16_t) * 3;
            case ElementType::USHORT4:
                return sizeof(uint16_t) * 4;

            case ElementType::INT:
                return sizeof(int32_t);

            case ElementType::UINT:
                return sizeof(uint32_t);

            case ElementType::FLOAT:
                return sizeof(float);
            case ElementType::FLOAT2:
                return sizeof(float) * 2;
            case ElementType::FLOAT3:
                return sizeof(float) * 3;
            case ElementType::FLOAT4:
                return sizeof(float) * 4;

            case ElementType::HALF:
                return sizeof(uint16_t);
            case ElementType::HALF2:
                return sizeof(uint16_t) * 2;
            case ElementType::HALF3:
                return sizeof(uint16_t) * 3;
            case ElementType::HALF4:
                return sizeof(uint16_t) * 4;
        }

        return 0;
    }

    using AttributeData = std::vector<Attribute>;

    class VertexBufferLayout {
    public :
        VertexBufferLayout() = default;

        explicit VertexBufferLayout(const AttributeData& attributes);

        void attribute(Attribute attribute);

        const AttributeData& getAttributes() const { return mAttributes; }

        uint32_t getStride() const { return mStride; }

    private :
        AttributeData mAttributes;
        uint32_t mStride = 0;
    };
}
