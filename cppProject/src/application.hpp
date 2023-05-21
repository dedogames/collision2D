#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <iostream>
#include "renders/graphBase.hpp"
#include "renders/imgGuiRender/imgGui.hpp"
#include <memory>
#include "engine/gelEngine.hpp"
namespace App
{

    class Application
    {

    public:
        void start()
        {
            std::cout << "Start Application" << std::endl;

            renders::imgGuiRender::GraphImgGui::getInstance().init();
            gelEnginePtr = std::make_unique<engine::GelEngine>();
            gelEnginePtr->start();
        }

        void run()
        {
            std::cout << "Run Application" << std::endl;
            // Initialize Loop
            renders::imgGuiRender::GraphImgGui::getInstance().setCallBackLoop([&](float timeStep)
                                                                              {
            gelEnginePtr->draw();
            gelEnginePtr->update(timeStep); });
        }

        void shutDown()
        {
            std::cout << "ShutDown Application" << std::endl;
        }

        std::unique_ptr<engine::GelEngine> gelEnginePtr;
    };

}

#endif