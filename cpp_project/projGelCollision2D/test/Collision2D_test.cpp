#include "Math.hpp"

#include <gtest/gtest.h>

TEST(Collision2DTest, TestVec)
{ 
    Engine::Vec2 v =  Engine::Vec2(1.0f, 0.0f);
    ASSERT_EQ(v.x, 1.0f );    
}
 