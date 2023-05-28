#ifndef UTILS_COLLISION_HPP
#define UTILS_COLLISION_HPP

#include "Arbiter.hpp"
namespace engine{
    namespace core{
        namespace collision
        {
enum Axis
{
	FACE_A_X,
	FACE_A_Y,
	FACE_B_X,
	FACE_B_Y
};

enum EdgeNumbers
{
	NO_EDGE = 0,
	EDGE1,
	EDGE2,
	EDGE3,
	EDGE4
};

struct ClipVertex
{
	ClipVertex() { fp.value = 0; }
	Vec2 v;
	FeaturePair fp;
};

        }
     }
}

#endif