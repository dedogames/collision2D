#include "graphBase.hpp"

namespace renders
{

    GraphBase::GraphBase()
    {
        m_keysPressed.insert(std::pair<EKey, bool>(EKey::ARROW_UP, false));
        m_keysPressed.insert(std::pair<EKey, bool>(EKey::ARROW_LEFT, false));
        m_keysPressed.insert(std::pair<EKey, bool>(EKey::ARROW_RIGHT, false));
        m_keysPressed.insert(std::pair<EKey, bool>(EKey::ARROW_DOWN, false));
        m_keysPressed.insert(std::pair<EKey, bool>(EKey::A, false));
        m_keysPressed.insert(std::pair<EKey, bool>(EKey::C, false));
    }

    Vec2 GraphBase::getMousePos()
    {

        return m_mousePosition;
    }
    EStatesButtomMouse GraphBase::getStateButtonMouse()
    {
        return m_stateButtonMouse;
    }
    void GraphBase::setKeyPressed(EKey key, bool val)
    {
        m_keysReleased = false;
        m_keysPressed[key] = val;
    }

    void GraphBase::setKeyPressed(int key, bool val)
    {
        m_keysReleased = false;
        try
        {
            m_keysPressed[static_cast<EKey>(key)] = val;
        }
        catch (const std::exception &e)
        {
        }
    }

    bool GraphBase::noKeysPresed()
    {
        return m_keysReleased;
    };

    void GraphBase::resetKeys()
    {
        m_keysReleased = true;
        for (auto &keyProp : m_keysPressed)
        {
            keyProp.second = false;
        }
    }

    bool GraphBase::isKeyPressed(EKey key)
    {
        try
        {
            bool k= m_keysPressed[key];
            if(k){
                return true;
            }
            
        }
        catch (const std::exception &e)
        {
            return false;
        }
        return false;
    }

    bool GraphBase::isKeyPressed(int key)
    {
        try
        {
            return m_keysPressed[static_cast<EKey>(key)];
        }
        catch (const std::exception &e)
        {
            return false;
        }
    }
}
