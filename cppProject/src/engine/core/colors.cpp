#include "colors.hpp"
namespace engine
{
    namespace core
    {

        std::map<ETypeColor, ColorSt> Color::ColorStsMap = std::map<ETypeColor, ColorSt>{
            {ETypeColor::DARKGREY, ColorSt{0.4, 0.4, 0.4}},
            {ETypeColor::RED, ColorSt{1.0, 0.0, 0.0}},
            {ETypeColor::GREEN, ColorSt{0.0, 1.0, 0.0}},
            {ETypeColor::BLUE, ColorSt{0.0, 0.0, 1.0}},
            {ETypeColor::CYAN, ColorSt{0.0, 1.0, 1.0}},
            {ETypeColor::MAGENTA, ColorSt{1.0, 0.0, 1.0}},
            {ETypeColor::YELLOW, ColorSt{1.0, 1.0, 0.0}},
            {ETypeColor::WHITE, ColorSt{1.0, 1.0, 1.0}},
            {ETypeColor::BLACK, ColorSt{0.0, 0.0, 0.0}},
            {ETypeColor::DARKRED, ColorSt{0.5, 0.0, 0.0}},
            {ETypeColor::DARKGREEN, ColorSt{0.0, 0.5, 0.0}},
            {ETypeColor::DARKBLUE, ColorSt{0.0, 0.0, 0.5}},
            {ETypeColor::DARKCYAN, ColorSt{0.0, 0.5, 0.5}},
            {ETypeColor::RKMAGENTA, ColorSt{0.5, 0.0, 0.5}},
            {ETypeColor::ARKYELLOW, ColorSt{0.5, 0.5, 0.0}},
            {ETypeColor::LIGHTGREY, ColorSt{0.8, 0.8, 0.8}}};

    }
}