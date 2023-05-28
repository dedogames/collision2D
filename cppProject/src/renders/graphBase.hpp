#ifndef GRAPH_BASE_HPP
#define GRAPH_BASE_HPP
#include <iostream>
#include <string>
#include <functional>
#include "../engine/core/body.hpp"
#include "../engine/core/colors.hpp"
#include <map>
#include "keys.hpp"
using namespace engine::core;


namespace renders
{

    enum EStatesButtomMouse
    {
        PRESS,
        RELEASED,
        CLICKED
        
    };

    const float angleWingUp = 2.35619f;
    const float angleWingDown = 3.92699f; 
    class GraphBase
    {
    public:
        virtual void init() = 0;

        virtual void drawText(const std::string &text, int xPos, int yPos) = 0;
        virtual void DrawBody(Body *body, ETypeColor color) = 0;
        virtual void DrawVector(const engine::core::Vec2 &position, float len, float angle, engine::core::ETypeColor color) = 0;
        virtual void DrawPoint(const Vec2 &position, ETypeColor color) = 0;
        virtual void DrawLine( const engine::core::Vec2 &position,  const  engine::core::Vec2 &vec, engine::core::ETypeColor color) =0;
        virtual void DrawRect( const engine::core::Vec2 &position,  const Vec2& size, bool fill, engine::core::ETypeColor color, float angle) =0;
        virtual void DrawCircle(const engine::core::Vec2 &position, float radius,  bool fill, engine::core::ETypeColor color, float angle) = 0;
        virtual bool isRunning() = 0;
        virtual void setCallBackLoop( std::function<void(float)> callBack_loop) = 0;
       
        virtual ~GraphBase() {}
        GraphBase();
        bool isKeyPressed(EKey key);
        bool isKeyPressed(int key);
        void setKeyPressed(EKey key, bool val);
        void setKeyPressed(int key, bool val);
        Vec2 getMousePos();
        EStatesButtomMouse getStateButtonMouse();
        void resetKeys();
        bool noKeysPresed();

    protected:
        virtual void loop() = 0;

        bool m_keysReleased;
        std::map<EKey, bool> m_keysPressed;
        Vec2 m_mousePosition;
        EStatesButtomMouse m_stateButtonMouse;
    };
};

#endif