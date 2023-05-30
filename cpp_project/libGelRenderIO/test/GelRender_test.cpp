#include "FooGelRender.hpp"
#include "Math.hpp"
#include <gtest/gtest.h>

TEST(FooRenderTest, TestRotation)
{
    // Engine::FooEngine eng{Engine::Vec2(10.0f, 5.0f)};
    Render::FooGelRender render{};
    Engine::Mat22 rot = render.rotate(0.0f);
    ASSERT_EQ(rot.col1.x, 1 );  
    ASSERT_EQ(rot.col2.y, 1 );  
}
 