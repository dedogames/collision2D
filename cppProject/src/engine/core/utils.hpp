#ifndef UTILS_HPP
#define UTILS_HPP
#include "math.hpp"
namespace engine
{
    namespace core
    {
        //https://stackoverflow.com/questions/2752725/finding-whether-a-point-lies-inside-a-rectangle-or-not#:~:text=In%20any%20case%2C%20for%20any,test%20%2D%20the%20point%20is%20inside.
        bool isPointInsideRect(const Vec2 &point, const Vec2 &centerPointRect, const Vec2 &sizeRect, float angle = 0)
        {

            Mat22 R(angle);
            Vec2 x = centerPointRect;
            Vec2 h = 0.5f * sizeRect;

            Vec2 p1 = x + R * Vec2(-h.x, -h.y);
            Vec2 p2 = x + R * Vec2(h.x, -h.y);
            Vec2 p3 = x + R * Vec2(h.x, h.y);

            Vec2 p4 = x + R * Vec2(-h.x, h.y);

            Vec2 v1 = p1 - p2;
            Vec2 v2 = p1 - point;
            Vec2 v3 = p2 - p3;
            Vec2 v4 = p2 - point;

            float d1 = Dot(v1, v2);
            float d2 = Dot(v1, v1);
            float d3 = Dot(v3, v4);
            float d4 = Dot(v3, v3);

            return 0 <= d1 && d1 <= d2 && 0 <= d3 && d3 <= d4;
        }

    }
}
#endif