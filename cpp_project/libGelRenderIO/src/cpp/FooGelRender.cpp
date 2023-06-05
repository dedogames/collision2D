#include "FooGelRender.hpp"
#include "utils/Log.hpp"

namespace Render
{
      using namespace Utils;
      FooGelRender::FooGelRender()
      {
            Engine::Vec2 pos(10.0f, 5.0f);
            Engine::Vec2 mousePos(100.0f, 14.0f);
            Engine::Vec2 dif = mousePos - pos;

            Log(INFO) << "GelRender call GelEngine (pos-mousePos) = " << dif.toString() << Log::endl();
      }

      Engine::Mat22 FooGelRender::rotate(float angle)
      {
            Engine::Mat22 rot(angle);
            return rot;
      }
}