 
#include "FooEngine.hpp"
#include "FooGelRender.hpp"
#include "utils/log.hpp"

using namespace Render::Utils;
int main()
{
    Log() << "\n\n*************************************************\n"<<Log::endl();

    Log() << "Base Project cmake using C++17 and multiple projects."<<Log::endl()<<Log::endl();
    Log() << "1 - libGelEngine - Implementation of or Engine"<<Log::endl();
    Engine::FooEngine eng = Engine::FooEngine{}; Log()<<Log::endl();
    Log() << "2 - libGelRenderIO - Build a graph and IO library"<<Log::endl();
    Render::FooGelRender l_render =  Render::FooGelRender{}; Log() <<Log::endl();
    Log() << "3 - projGelCollision2D - Join everthing with pratical exemples"<<Log::endl();
    Log() << "  - Join projects 1 and 2 with main.cpp" << Log::endl()<<Log::endl();
    Log() << "\n*************************************************\n"<<Log::endl();
    Log() << " 'We are not what we know but what we are willing to learn.'" << Log::endl();
    Log() << "  Parker Palmer\n" << Log::endl();
    Log() << "Main executed with " << " arguments" << Log::endl() << Log::endl() ;

}