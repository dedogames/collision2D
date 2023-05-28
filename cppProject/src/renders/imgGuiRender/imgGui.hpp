#define _CRT_SECURE_NO_WARNINGS
#ifndef IMG_GUI_RENDER_HPP
#define IMG_GUI_RENDER_HPP
#include <functional>
#include <iostream>
#include <string>
#include "../graphBase.hpp"
#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "imgui/imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl2.h"
#include "../../engine/core/body.hpp"
#include "../../engine/core/colors.hpp"

namespace renders
{
    namespace imgGuiRender
    {
        using namespace engine::core;
        class GraphImgGui : public GraphBase
        {

        public:
            virtual void drawText(const std::string &text, int xPos, int yPos);
            virtual void init();

            virtual void DrawBody(Body* body,ETypeColor color);
            virtual void DrawVector(const engine::core::Vec2 &position, float len, float angle, engine::core::ETypeColor color) ;
            virtual void DrawPoint(const Vec2& position , ETypeColor color);
            virtual void DrawLine(const engine::core::Vec2 &start, const engine::core::Vec2 &end,  engine::core::ETypeColor color);
            virtual void DrawRect( const engine::core::Vec2 &position,  const Vec2& size, bool fill, engine::core::ETypeColor color=engine::core::ETypeColor::WHITE, float angle = 0 );
            virtual void DrawCircle(const engine::core::Vec2 &position, float radius,  bool fill, engine::core::ETypeColor color, float angle);
            virtual ~GraphImgGui() {}
            virtual void setCallBackLoop( std::function<void(float)> callBack_loop);

            // static GraphImgGui &getInstance()
            // {
            //     if (!m_instance)
            //     {
            //         m_instance = new GraphImgGui();
            //     }
            //     return *m_instance;
            // }
            virtual bool isRunning();
            GraphImgGui();
        protected:
         
            virtual void loop();

        private: // methods
            void reshape(GLFWwindow *, int w, int h);
            void keyboard(GLFWwindow *window, int key, int scancode, int action, int mods);

           // static GraphImgGui *m_instance;
            GLFWwindow *m_mainWindow = NULL;
            int m_width = 1280;
            int m_height = 720;
            float m_zoom = 10.0f;
            float m_pan_y = 8.0f;
            std::function<void(float)> m_callBack_loop;
            float m_timeStep = 1.0f / 60.0f;
        };
    };
};

#endif