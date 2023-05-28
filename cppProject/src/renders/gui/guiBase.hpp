#ifndef GUI_BASE_HPP
#define GUI_BASE_HPP
#include <vector>
#include <memory>
#include <functional>
#include <vector>
#include "../../engine/core/math.hpp"
#include "../graphBase.hpp"
#include <tuple>
#include <functional>
#include <utility>
#include <type_traits>

namespace renders
{

    enum ETypeGui
    {
        UNKNOWN,
        BUTTOM
    };

    template <typename... Args>
    class GuiBase
    {

    public:
        virtual void draw(const   GraphBase&  render) = 0;
        virtual void update(const engine::core::Vec2 &mousePosition) = 0;
        GuiBase(Args... params):m_args(std::forward<Args>(params)...){};
        GuiBase():m_args(){}
        virtual ~GuiBase() {}

    protected:
        engine::core::Vec2 m_position;
        std::vector<unsigned int> m_listColors;
        std::vector<unsigned int> m_states;
        std::tuple<Args...> m_args;
        ETypeGui m_typeGui;
    };
}

#endif