#include "FooEngine.hpp"
#include "Math.hpp"
#include <gtest/gtest.h>

TEST(FooEngineTest, TesthalfSize)
{
    Engine::FooEngine eng{Engine::Vec2(10.0f, 5.0f)};
    Engine::Vec2 expectedHalfSize = Engine::Vec2(5.0f, 2.5f);
    ASSERT_EQ(eng.getHalfSize().x,expectedHalfSize.x ); 
    ASSERT_EQ(eng.getHalfSize().y,expectedHalfSize.y );
}
 