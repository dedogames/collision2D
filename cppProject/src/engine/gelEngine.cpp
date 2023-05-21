#include "gelEngine.hpp"
#include <iostream>
#include "../renders/imgGuiRender/imgGui.hpp"

namespace engine
{
    void GelEngine::draw()
    {
        renders::imgGuiRender::GraphImgGui::getInstance().drawText("Hello graphics!", 10, 10);

        for (auto &body : m_bodies)
        {
                renders::imgGuiRender::GraphImgGui::getInstance().DrawBody(body);  
        }
    }

    void GelEngine::start()
    {
        GelEngine* self = this;
        core::Body * newBody = new core::Body();
        newBody->Set(Vec2(100.0f, 20.0f), FLT_MAX);
        newBody->position.Set(0.0f, -0.5f * newBody->width.y);
        m_bodies.push_back(newBody);
        newBody = new core::Body();
        newBody->Set(Vec2(1.0f, 1.0f), 200.0f);
        newBody->position.Set(0.0f, 4.0f);
        m_bodies.push_back(newBody);
       
    }
    void GelEngine::update(int deltaTime)
    {
    }
};
