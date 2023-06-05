#include "FooEngine.hpp"

namespace Engine
{
    FooEngine::FooEngine(const  Vec2 &size) : m_size(size)
    {
    }

    Vec2 FooEngine::getHalfSize()
    {
        return  0.5f * m_size;
    }
}