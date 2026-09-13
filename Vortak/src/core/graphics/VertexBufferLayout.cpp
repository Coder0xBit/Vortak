#include "core/graphics/VertexBufferLayout.h"

namespace Vortak {
    VertexBufferLayout::VertexBufferLayout(const AttributeData& attributes) {
        mAttributes = attributes;
        for (const auto& attribute : mAttributes) {
            mStride += getElementSize(attribute.type);
        }
    }

    void VertexBufferLayout::attribute(Attribute attribute) {
        mStride += getElementSize(attribute.type);
        mAttributes.push_back(attribute);
    }
}
