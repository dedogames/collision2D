#ifndef FOO_ENGINE_HPP
#define FOO_ENGINE_HPP

#include "Math.hpp"
namespace Engine
{
    class FooEngine
    {
    public:
        FooEngine(const Vec2 &size = Vec2(0.0f, 0.0f));
        Vec2 getHalfSize();

    private:
        Vec2 m_size;
    };
}
#endif