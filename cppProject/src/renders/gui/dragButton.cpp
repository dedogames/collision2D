#include "dragButton.hpp"
#include "../gui/guiBase.hpp"
namespace renders
{
 
   DragButton::DragButton(const Vec2& position, const Vec2& size,  unsigned int color,float rotation):GuiBase(position,size,color,rotation),
   m_position( std::get<0>(m_args)), m_size( std::get<1>(m_args)),m_color( std::get<2>(m_args)), m_rotation(std::get<3>(m_args))
   { 
   }
// draw(const renders::imgGuiRender::GraphImgGui&  m_render)
  


   
    void DragButton::update(const Vec2& mousePosition) 
    {
       // render.DrawLine(posButton, mousePosition, WHITE);
      //  render.DrawPoint(mousePosition, GREEN);

       // engine::core::ETypeColor colorRect = WHITE;
        // if (isPointInsideRect(mousePosition, posButton, sizeButton, angle))
        // {
        //     colorRect = YELLOW;
        // }

        //render.DrawPoint(posButton, YELLOW);
       

    } 

    void DragButton::draw(const  GraphBase&  render) 
   {

   }


}