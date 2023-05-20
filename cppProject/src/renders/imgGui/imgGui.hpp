#include<functional>
#include<iostream>
#include<string>
#include "../graphBase.hpp"
namespace renders{
    namespace imgGui{

        class GraphImgGui : GraphBase{

            public:
             GraphImgGui();
            void drawText(std::string& text, int xPos, int yPos);
            bool isRunning();
            void reshape(int w, int h);
            void loop(std::function<void(void)> callBack);
        };
    }
}