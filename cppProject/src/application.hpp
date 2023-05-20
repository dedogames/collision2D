#include<iostream>

namespace App{

class Application{

    public:
    void start()
    {
        std::cout << "Start Application" << std::endl;
    }

    void run()
    {
        std::cout << "Run Application" << std::endl;
    }

    void shutDown()
    {
        std::cout << "ShutDown Application" << std::endl;
    }
};

}