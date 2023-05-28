#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include <iostream>
#include "renders/graphBase.hpp"
#include "renders/imgGuiRender/imgGui.hpp"
#include "renders/graphBase.hpp"
#include <memory>
#include "engine/gelEngine.hpp"
namespace App
{

    class Application
    {

    public:
        Application():gelEngine(engine::GelEngine{std::make_unique<renders::imgGuiRender::GraphImgGui>()}){}
        void start()
        {
            std::cout << "Start Application" << std::endl;

            // renders::imgGuiRender::GraphImgGui::getInstance().init();
            // gelEnginePtr = std::make_unique<engine::GelEngine>();
            //  gelEnginePtr->start();
            //    std::unique_ptr<renders::imgGuiRender::GraphImgGui> gui = std::make_unique<renders::imgGuiRender::GraphImgGui>();
            // gelEngine = ;
              gelEngine.start();
        }

        void run()
        {
            std::cout << "Run Application" << std::endl;
            // Initialize Loop
              gelEngine.run();
       
        }

        void shutDown()
        {
            std::cout << "ShutDown Application" << std::endl;
        }

    private:
        engine::GelEngine gelEngine;
        // std::unique_ptr<engine::GelEngine> gelEnginePtr;
    };

}

#endif