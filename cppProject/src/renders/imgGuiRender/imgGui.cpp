#include "imgGui.hpp"
#include <iostream>
#include <string>

namespace renders
{
    namespace imgGuiRender
    {
      //  GraphImgGui *GraphImgGui::m_instance = nullptr;
        static void glfwErrorCallback(int error, const char *description)
        {
            printf("GLFW error %d: %s\n", error, description);
        }


        void GraphImgGui::keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            //m_keysPressed.push_back( static_cast<Keys>(key));
          

            setKeyPressed(key,true);

            if(action == GLFW_RELEASE)
            {
               resetKeys();
            }

       

            // if (action != GLFW_PRESS)
            // {
            //     return;
            // }

      

            // switch (key)
            // {
            // case GLFW_KEY_ESCAPE:
            //     // Quit
            //     glfwSetWindowShouldClose(m_mainWindow, GL_TRUE);
            //     break;

            // case GLFW_KEY_A:

            //     break;

            // case GLFW_KEY_P:

            //     break;

            // case GLFW_KEY_W:

            //     break;
            // }
        }

        GraphImgGui::GraphImgGui() : m_zoom(10.0f), m_pan_y(0.0f), m_width(1280), m_height(720) {
          
        }
        void GraphImgGui::drawText(const std::string &text, int x, int y)
        {
            ImVec2 p;
            p.x = float(x);
            p.y = float(y);
            ImGui::Begin("Overlay", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar);
            ImGui::SetCursorPos(p);
            ImGui::TextColored(ImColor(230, 153, 153, 255), "%s", text.c_str());
            ImGui::End();
        }
        bool GraphImgGui::isRunning()
        {
            return false;
        }
        
        
        void GraphImgGui::reshape(GLFWwindow *, int w, int h)
        {
            m_width = w;
            m_height = h > 0 ? h : 1;

            glViewport(0, 0, m_width, m_height);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            float aspect = float(m_width) / float(m_height);
            if (m_width >= m_height)
            {
                // aspect >= 1, set the height from -1 to 1, with larger width
                glOrtho(-m_zoom * aspect, m_zoom * aspect, -m_zoom + m_pan_y, m_zoom + m_pan_y, -1.0, 1.0);
            }
            else
            {
                // aspect < 1, set the width to -1 to 1, with larger height
                glOrtho(-m_zoom, m_zoom, -m_zoom / aspect + m_pan_y, m_zoom / aspect + m_pan_y, -1.0, 1.0);
            }
        }

        void  GraphImgGui::DrawVector(const engine::core::Vec2 &position, float len, float angle, engine::core::ETypeColor color)
        {
            /*              -WingUp
                              -       
                               ( - angle - 135 degree or 2.35619 radisn
            pos-----------------vec
                               ( - angle 225 degree or 3.92699 radians
                              -
                            - WinDown


            */


            Mat22 RotVec(angle);  
            Vec2 v1 = position + RotVec*Vec2(len,0);

            Vec2 vUp =  (v1 + RotVec  *  (Mat22(angleWingUp)   * Vec2(1,0)));
            Vec2 vDown =  (v1 + RotVec * (Mat22(angleWingDown) *  Vec2(1,0) ));

            Vec2 v2 =  vUp;
            Vec2 v3 =  vDown;

            DrawPoint(position,engine::core::ETypeColor::LIGHTGREY );
            DrawPoint(v1,engine::core::ETypeColor::LIGHTGREY );
            DrawLine(position, v1, color);
            DrawLine(v1, v2, color);
            DrawLine(v1, v3, color);
        }


        void GraphImgGui::DrawRect( const engine::core::Vec2 &position,  const Vec2& size, bool fill, engine::core::ETypeColor color , float angle )
        {
            Mat22 R(angle);
            Vec2 x = position;
            Vec2 h = 0.5f * size;

            uint  typeShape = GL_LINE_LOOP;
            if(fill)
            {
                typeShape = GL_POLYGON;
            }

            Vec2 v1 = x + R * Vec2(-h.x, -h.y);
            Vec2 v2 = x + R * Vec2(h.x, -h.y);
            Vec2 v3 = x + R * Vec2(h.x, h.y);
            Vec2 v4 = x + R * Vec2(-h.x, h.y);
            engine::core::ColorSt cColor = engine::core::Color::ColorStsMap[color];
            glColor3f(cColor.r, cColor.g, cColor.b );
            glBegin(typeShape);
                glVertex2f(v1.x, v1.y);
                glVertex2f(v2.x, v2.y);
                glVertex2f(v3.x, v3.y);
                glVertex2f(v4.x, v4.y);
            glEnd();
        }

        void GraphImgGui::DrawCircle(const engine::core::Vec2 &position, float radius,  bool fill, engine::core::ETypeColor color, float angle)
        {
                std::cout << "Not implemented yet!"<<std::endl;
        }
        void  GraphImgGui::DrawLine(const engine::core::Vec2 &start, const engine::core::Vec2 &end,  engine::core::ETypeColor color)
        {
            
            engine::core::ColorSt cColor = engine::core::Color::ColorStsMap[color];
            glColor3f(cColor.r, cColor.g, cColor.b );

            glBegin(GL_LINE_LOOP);
            glVertex2f(start.x, start.y);
            glVertex2f(end.x, end.y); 
            glEnd();
        }
        void  GraphImgGui::DrawPoint(const engine::core::Vec2 &position, engine::core::ETypeColor color)
        {
            glPointSize(6.0f);
            engine::core::ColorSt cColor = engine::core::Color::ColorStsMap[color];
            glColor3f(cColor.r, cColor.g, cColor.b );
            glBegin(GL_POINTS);
            glVertex2f(position.x, position.y);
            glEnd();
		    glPointSize(1.0f);
        }

         
        void GraphImgGui::DrawBody(engine::core::Body *body, engine::core::ETypeColor color)
        {
            Mat22 R(body->rotation);
            Vec2 x = body->position;
            Vec2 h = 0.5f * body->width;

            Vec2 v1 = x + R * Vec2(-h.x, -h.y);
            Vec2 v2 = x + R * Vec2(h.x, -h.y);
            Vec2 v3 = x + R * Vec2(h.x, h.y);
            Vec2 v4 = x + R * Vec2(-h.x, h.y);
            engine::core::ColorSt cColor = engine::core::Color::ColorStsMap[color];
            glColor3f(cColor.r, cColor.g, cColor.b );

            glBegin(GL_LINE_LOOP);
            glVertex2f(v1.x, v1.y);
            glVertex2f(v2.x, v2.y);
            glVertex2f(v3.x, v3.y);
            glVertex2f(v4.x, v4.y);
            glEnd();
        }
        void GraphImgGui::setCallBackLoop(std::function<void(float)> callBack_loop)
        {
            this->m_callBack_loop = callBack_loop;
            loop();
        }

        void GraphImgGui::loop()
        {

            while (!glfwWindowShouldClose(m_mainWindow))
            {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                ImGui_ImplOpenGL2_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();

                // Globally position text
                ImGui::SetNextWindowPos(ImVec2(10.0f, 10.0f));
                ImGui::Begin("Overlay", NULL, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoInputs | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoScrollbar);
                ImGui::End();

                m_callBack_loop(m_timeStep);

                glMatrixMode(GL_MODELVIEW);
                glLoadIdentity();

                glEnd();
                glPointSize(1.0f);

                ImGui::Render();
                ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

                glfwPollEvents();
                glfwSwapBuffers(m_mainWindow);
            }
        }

        void GraphImgGui::init()
        {
            std::cout << " Initialize GraphImgGui" << std::endl;

            glfwSetErrorCallback(glfwErrorCallback);

            if (glfwInit() == 0)
            {
                fprintf(stderr, "Failed to initialize GLFW\n");
                return;
            }

            m_mainWindow = glfwCreateWindow(m_width, m_height, "box2d-lite", NULL, NULL);
            if (m_mainWindow == NULL)
            {
                fprintf(stderr, "Failed to open GLFW mainWindow.\n");
                glfwTerminate();
                return;
            }

            glfwMakeContextCurrent(m_mainWindow);

            // Load OpenGL functions using glad
            int gladStatus = gladLoadGL();
            if (gladStatus == 0)
            {
                fprintf(stderr, "Failed to load OpenGL.\n");
                glfwTerminate();
                return;
            }

            glfwSwapInterval(1);

            // Resize Handler
            glfwSetWindowUserPointer(m_mainWindow, this);
            auto reshapeFunc = [](GLFWwindow *w, int x, int y)
            {
                static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->reshape(w, x, y);
            };
            glfwSetWindowSizeCallback(m_mainWindow, reshapeFunc);

            //Keyboard handler
            auto keyboardHandler = [](GLFWwindow *w, int key, int scancode, int action, int mods)
            {
                std::cout << key << std::endl;
                static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->keyboard(w, key, scancode, action, mods);
            };

            glfwSetKeyCallback(m_mainWindow, keyboardHandler);

            //Mouse Press Handler
            auto mousePressHandler = [](GLFWwindow *w,int button, int action, int mods){

                      if( action == GLFW_PRESS)
                      {
                              static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->m_stateButtonMouse = EStatesButtomMouse::PRESS;
                      }

                      if(  action == GLFW_RELEASE)
                      {
                       
                            static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->m_stateButtonMouse = EStatesButtomMouse::RELEASED;
                      } 
             
            };
            glfwSetMouseButtonCallback(m_mainWindow, mousePressHandler);
              float aspect = float(m_width) / float(m_height);
            //Move
             auto mouseMoveHandler = [](GLFWwindow *w, double x, double y)
             {

 
                  //  double xpos, ypos;
                   // glfwGetCursorPos(w, &xpos, &ypos);
                  //  std::cout << "Position: (" << xpos <<":"  << ypos << ")"<<std::endl;

                  int width, h;
                glfwGetWindowSize( w, &width, &h );

                ImVec4 clip_space;
                clip_space.x =   17.7777779*(x / ((width/2) )-1);
                clip_space.y =   -10* ( y / ((h/2) )-1);
                
                   static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->m_mousePosition = Vec2(clip_space.x, clip_space.y);
             };

            glfwSetCursorPosCallback(m_mainWindow,mouseMoveHandler);

         
            float xscale, yscale;
            glfwGetWindowContentScale(m_mainWindow, &xscale, &yscale);
            float uiScale = xscale;

            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGui::StyleColorsClassic();
            ImGui_ImplGlfw_InitForOpenGL(m_mainWindow, true);
            ImGui_ImplOpenGL2_Init();
            ImGuiIO &io = ImGui::GetIO();
            io.FontGlobalScale = uiScale;

            glViewport(0, 0, m_width, m_height);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

          
            if (m_width >= m_height)
            {
                // aspect >= 1, set the height from -1 to 1, with larger width
                glOrtho(-m_zoom * aspect, m_zoom * aspect, -m_zoom + m_pan_y, m_zoom + m_pan_y, -1.0, 1.0);
            }
            else
            {
                // aspect < 1, set the width to -1 to 1, with larger height
                glOrtho(-m_zoom, m_zoom, -m_zoom / aspect + m_pan_y, m_zoom / aspect + m_pan_y, -1.0, 1.0);
            }
        }

    };
};
