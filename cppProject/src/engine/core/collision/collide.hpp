
#ifndef COLLIDE_HPP
#define COLLIDE_HPP

#include "../body.hpp"
#include "Arbiter.hpp"
#include "utils.hpp"

namespace engine{
    namespace core{
        namespace collision
        {
             void ComputeIncidentEdge(ClipVertex c[2], const Vec2& h, const Vec2& pos,const Mat22& Rot, const Vec2& normal);
             int Collide(Contact* contacts, Body* bodyA, Body* bodyB);
             
        } // namespace c
        
    }
}


#endif
