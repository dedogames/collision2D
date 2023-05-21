#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include<iostream>
#include "renders/graphBase.hpp"
#include "renders/imgGuiRender/imgGui.hpp"
#include <memory>
#include "engine/gelEngine.hpp"
namespace App{

class Application{

    public:
    void start()
    {
        std::cout << "Start Application" << std::endl;
        try
        {
           renders::imgGuiRender::GraphImgGui::getInstance().init(); 
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
       
    
        
    }


    void run()
    {
        std::cout << "Run Application" << std::endl;
            //Initialize Loop
        renders::imgGuiRender::GraphImgGui::getInstance().setCallBackLoop([&](){
            gelEnginePtr->draw();
            gelEnginePtr->update(0);
        });
    }

    void shutDown()
    {
        std::cout << "ShutDown Application" << std::endl;
    }

    std::unique_ptr<engine::GelEngine> gelEnginePtr;

};

}

#endif