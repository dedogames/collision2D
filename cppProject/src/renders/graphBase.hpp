#ifndef GRAPH_BASE_HPP
#define GRAPH_BASE_HPP
#include <iostream>
#include <string>
#include <functional>
namespace renders
{
    class GraphBase
    {
    public:
        virtual void init() = 0;
        virtual void drawText(std::string &text, int xPos, int yPos) = 0;
        virtual ~GraphBase(){}
        virtual bool isRunning() = 0;
        protected:
        virtual void loop() = 0;
       
    };
};

#endif