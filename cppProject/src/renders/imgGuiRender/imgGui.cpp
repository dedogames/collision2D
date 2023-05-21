#include "imgGui.hpp"
#include <iostream>
#include <string>

namespace renders
{
    namespace imgGuiRender
    {
        GraphImgGui *GraphImgGui::m_instance = nullptr;
        static void glfwErrorCallback(int error, const char *description)
        {
            printf("GLFW error %d: %s\n", error, description);
        }

        void GraphImgGui::keyboard(GLFWwindow *window, int key, int scancode, int action, int mods)
        {
            if (action != GLFW_PRESS)
            {
                return;
            }

            switch (key)
            {
            case GLFW_KEY_ESCAPE:
                // Quit
                glfwSetWindowShouldClose(m_mainWindow, GL_TRUE);
                break;

            case GLFW_KEY_A:

                break;

            case GLFW_KEY_P:

                break;

            case GLFW_KEY_W:

                break;
            }
        }

        GraphImgGui::GraphImgGui():m_zoom(10.0f), m_pan_y(8.0f), m_width(1280), m_height(720) {}
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

        void GraphImgGui::DrawBody(engine::core::Body *body)
        {
            Mat22 R(body->rotation);
            Vec2 x = body->position;
            Vec2 h = 0.5f * body->width;

            Vec2 v1 = x + R * Vec2(-h.x, -h.y);
            Vec2 v2 = x + R * Vec2(h.x, -h.y);
            Vec2 v3 = x + R * Vec2(h.x, h.y);
            Vec2 v4 = x + R * Vec2(-h.x, h.y);

            glColor3f(0.8f, 0.8f, 0.9f);

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

            glfwSetWindowUserPointer(m_mainWindow, this);
            auto reshapeFunc = [](GLFWwindow *w, int x, int y)
            {
                static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->reshape(w, x, y);
            };
            glfwSetWindowSizeCallback(m_mainWindow, reshapeFunc);

            auto keyboardHandler = [](GLFWwindow *w, int key, int scancode, int action, int mods)
            {
                static_cast<GraphImgGui *>(glfwGetWindowUserPointer(w))->keyboard(w, key, scancode, action, mods);
            };

            glfwSetKeyCallback(m_mainWindow, keyboardHandler);

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

    };
};



  