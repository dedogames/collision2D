#include "FooEngine.hpp"

namespace Engine
{
    FooEngine::FooEngine(const  Vec2 &size) : m_size(size)
    {
        std::cout << "  - Constructor call from libGelEngine project" << std::endl;
    }

    Vec2 FooEngine::halfSize()
    {
        return  0.5f * m_size;
    }
}