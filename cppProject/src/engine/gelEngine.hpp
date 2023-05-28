#ifndef GEL_ENGINE_HPP
#define GEL_ENGINE_HPP
#include "core/body.hpp"
#include <vector>
#include "../renders/gui/guiBase.hpp"
#include "../renders/gui/dragButton.hpp"
#include<memory>
namespace engine
{
    class GelEngine{

        public:
            void start();
            void draw( );
            void update(float deltaTime);
            void gui();
            void  run();
            void mouseEvent();
            GelEngine(std::unique_ptr<renders::GraphBase> render);

            std::vector<core::Body*> m_bodies;
            private:
            float speedX ;
            float speedY;
            std::string name = "test";
            std::vector< renders::GuiBase<const Vec2&/*position*/, const Vec2&,/*size*/ unsigned int/*color*/, float>*> m_buttons;
            std::unique_ptr<renders::GraphBase> m_render;
                 
    };
};

#endif