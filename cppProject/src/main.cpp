#define _CRT_SECURE_NO_WARNINGS
#include "application.hpp"
int main(int, char**)
{
    App::Application app;
    app.start();
    app.run();
    return 0;
}

