#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "guiBase.hpp"
#include "../graphBase.hpp"
#include <functional>
#include "../graphBase.hpp"
namespace renders
{
 

 

   class DragButton : public GuiBase<const Vec2&/*position*/, const Vec2&,/*size*/ unsigned int/*color*/,float/*m_rotation*/>
   {

   public:
   //position, size 
      DragButton(const Vec2& position, const Vec2& size,  unsigned int color,float rotation=0);
      virtual ~DragButton() {}
      virtual void draw(const   GraphBase&  render) ;
      virtual void update(const Vec2 &mousePosition) ;  

      protected:
       Vec2 m_position;
       Vec2 m_size;
       float m_rotation;
      unsigned int m_color;

   };

}

#endif