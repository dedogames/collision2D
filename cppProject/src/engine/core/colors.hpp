
#ifndef COLORS_TYPE_HPP
#define COLORS_TYPE_HPP
#include <map>

namespace engine
{
    namespace core
    {
        enum ETypeColor
            {
                DARKGREY,
                RED,
                GREEN,
                BLUE,
                CYAN,
                MAGENTA,
                YELLOW,
                WHITE,
                BLACK,
                DARKRED,
                DARKGREEN,
                DARKBLUE,
                DARKCYAN,
                RKMAGENTA,
                ARKYELLOW,
                LIGHTGREY
            };

            struct ColorSt
            {
               ColorSt() : r(1.0f), g(1.0f), b(1.0f) {}
               ColorSt(float _r, float _g, float _b) : r(_r), g(_g), b(_b) {}
                float r;
                float g;
                float b;
            };

         struct Color{
            static std::map<ETypeColor,ColorSt>ColorStsMap;
 
        };

        //Initialize
      
    };
};

#endif