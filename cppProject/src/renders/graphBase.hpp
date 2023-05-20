#include<iostream>
#include<string>
#include<functional>
namespace renders{
    class GraphBase {
        public:
        virtual void drawText(std::string& text, int xPos, int yPos) = 0;
        virtual bool isRunning() = 0;
        virtual void reshape(int w, int h) =0;
        virtual void loop(std::function<void(void)> callBack) =0;
    }; 
}