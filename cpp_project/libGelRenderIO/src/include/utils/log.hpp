#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <ostream>
#include <iostream>
#include <string>
#include <chrono>

#include <sstream>

using namespace std;
namespace Render
{
    namespace Utils
    {

        using namespace std;

        enum typelog
        {
            DEBUG,
            INFO,
            WARN,
            ERROR,
            CONSOLE
        };

        class Log
        {
        public:
            std::string getTimeStr()
            {
                std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

                std::string s(30, '\0');
                std::strftime(&s[0], s.size(), "%Y-%m-%d %H:%M:%S", std::localtime(&now));
                return s;
            }
            Log(typelog type = CONSOLE)
            {
                msglevel = type;

                if (type != CONSOLE)
                {
                    auto now = std::chrono::system_clock::now();
                    operator<<(getTimeStr()) << (" [" + getLabel(type) + "] ");
                }
            }
            virtual ~Log()
            {
            }

            static std::string endl()
            {

                return "\n";
            }

            template <class T>
            Log &operator<<(const T &msg)
            {

                cout << msg;
                return *this;
            }

        private:
            typelog msglevel = DEBUG;
            inline string getLabel(typelog type)
            {
                string label;
                switch (type)
                {
                case DEBUG:
                    label = "DEBUG";
                    break;
                case INFO:
                    label = "INFO";
                    break;
                case WARN:
                    label = "WARN";
                    break;
                case ERROR:
                    label = "ERROR";
                    break;
                default:
                    label = "";
                    break;
                }
                return label;
            }
        };
    }
}
#endif