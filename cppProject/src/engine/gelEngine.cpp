#include "gelEngine.hpp"
#include <iostream>
#include "../renders/imgGuiRender/imgGui.hpp"
#include "core/collision/collide.hpp"
#include <string>
#include "core/math.hpp"
#include "core/utils.hpp"
#include "../renders/keys.hpp"
#include "../renders/gui/delegate.hpp"
namespace engine
{
    float angle = 0;
    Vec2 pos = Vec2(0, 0);
    bool isMouseOver = false;
    int pressOnlyOnce = 0;

    Vec2 mousePosition;

    GelEngine::GelEngine(std::unique_ptr<renders::GraphBase> render) : m_render(std::move(render))
    {

        m_render->init();
      
    }

      void GelEngine::run()
      {
          m_render->setCallBackLoop([&](float timeStep)
                                  {
                 draw();
                update(timeStep); });

      }
    void GelEngine::draw()
    {
        m_render.get()->drawText("Hello graphics!", 10, 10);
        m_buttons[0]->draw(*m_render.get());
        // renders::imgGuiRender::GraphImgGui::getInstance()
        //  core::collision::Contact contacts[2];
        //  int result = core::collision::Collide(contacts, m_bodies[0], m_bodies[1]);
        //  if (result > 0)
        //  {
        //      std::string text = "Has Collision Contacts:" + std::to_string(result);
        //      renders::imgGuiRender::GraphImgGui::getInstance().drawText(text, 10, 40);
        //  }

        // for (auto &body : m_bodies)
        // {
        //     renders::imgGuiRender::GraphImgGui::getInstance().DrawBody(body, WHITE);
        // }
    }

    /**
     *
     *  GelEngine *self = this;
        core::Body *newBody = new core::Body();
        newBody->Set(Vec2(2.0f, 2.0f), 200.0f);
                newBody->position.Set( 5.0f, 2.0f);
        newBody->rotation = 0.78;
        m_bodies.push_back(newBody);
        newBody = new core::Body();
        newBody->Set(Vec2(2.0f, 2.0f), 200.0f);
                newBody->position.Set( 5.0f, 5.0f);

        m_bodies.push_back(newBody);
    */

    void GelEngine::start()
    {

        // GelEngine *self = this;
        // core::Body *newBody = new core::Body();
        // newBody->Set(Vec2(2.0f, 2.0f), 200.0f);
        //         newBody->position.Set( 3.0f, 3.0f);

        // m_bodies.push_back(newBody);
        // newBody = new core::Body();
        // newBody->Set(Vec2(2.0f, 2.0f), 200.0f);
        //         newBody->position.Set( 4.0f, 4.0f);

        // m_bodies.push_back(newBody);
        std::cout << " Start" << std::endl;
        gui();
    }

    void GelEngine::mouseEvent()
    {
        mousePosition = m_render.get()->getMousePos();
        m_render.get()->drawText("Real Mouse Position: " + mousePosition.toString(), 10, 40);
        renders::EStatesButtomMouse stateMouse = m_render.get()->getStateButtonMouse();

        if (stateMouse == renders::EStatesButtomMouse::PRESS)
        {

            pressOnlyOnce += 1;
        }
        else if (stateMouse == renders::EStatesButtomMouse::RELEASED)
        {
            pressOnlyOnce = 0;
        }

        if (pressOnlyOnce == 1)
        {

            std::cout << "Button Pressed" << std::endl;
        }
    }

    void GelEngine::gui()
    {
        // renders::GuiBase* newButton = new renders::DragButton();

        m_buttons.push_back(new renders::DragButton(Vec2(0, 0), Vec2(2, 2), WHITE, 0));
    }

    void GelEngine::update(float deltaTime)
    {
        // Body* bodyA = m_bodies[0];
        // renders::imgGuiRender::GraphImgGui render = renders::imgGuiRender::GraphImgGui::getInstance();

        //    renders::EStatesButtomMouse stateMouse = render.getStateButtonMouse();

        m_buttons[0]->update(mousePosition);

        // if(stateMouse ==  renders::EStatesButtomMouse::PRESS){
        //    // render.drawText("Button Pressed",10,40);
        //      m_buttons[0]->getCallBack()(stateMouse,mousePosition);
        //     pressOnlyOnce += 1;
        // }else if(stateMouse ==  renders::EStatesButtomMouse::RELEASED){
        //     pressOnlyOnce = 0;
        //      m_buttons[0]->getCallBack()(stateMouse,mousePosition);
        // }

        // if(pressOnlyOnce == 1){

        //       m_buttons[0]->getCallBack()(stateMouse,mousePosition);
        //    std::cout << "Button Pressed" <<std::endl;
        // }

        //
    }
};
