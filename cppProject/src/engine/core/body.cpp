#include "body.hpp"

namespace engine
{
    namespace core
    {
        Body::Body()
        {
            position.Set(0.0f, 0.0f);
            rotation = 0.0f;
            velocity.Set(0.0f, 0.0f);
            angularVelocity = 0.0f;
            force.Set(0.0f, 0.0f);
            torque = 0.0f;
            friction = 0.2f;

            width.Set(1.0f, 1.0f);
            mass = FLT_MAX;
            invMass = 0.0f;
            I = FLT_MAX;
            invI = 0.0f;
        }

        void Body::Set(const Vec2 &w, float m)
        {
            position.Set(0.0f, 0.0f);
            rotation = 0.0f;
            velocity.Set(0.0f, 0.0f);
            angularVelocity = 0.0f;
            force.Set(0.0f, 0.0f);
            torque = 0.0f;
            friction = 0.2f;

            width = w;
            mass = m;

            if (mass < FLT_MAX)
            {
                invMass = 1.0f / mass;
                I = mass * (width.x * width.x + width.y * width.y) / 12.0f;
                invI = 1.0f / I;
            }
            else
            {
                invMass = 0.0f;
                I = FLT_MAX;
                invI = 0.0f;
            }
        }

    }
}