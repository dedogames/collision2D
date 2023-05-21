#ifndef GEL_ENGINE_HPP
#define GEL_ENGINE_HPP
#include "core/body.hpp"
#include <vector>
namespace engine
{
    class GelEngine{

        public:
            void start();
            void draw();
            void update(int deltaTime);

            std::vector<core::Body*> m_bodies;
    };
};

#endif