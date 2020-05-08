#include "Window.h"

bool keys[1024];
int Window::Init()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /* Create a windowed mode window and its OpenGL context */
    m_GLFWWindow = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!m_GLFWWindow)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(m_GLFWWindow);

    //
    glfwSwapInterval(1);
    /*Init Glew After Having A Valid Context*/
    if (glewInit() != GLEW_OK)
        std::cout << "ERROR" << std::endl;

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);

    
    m_ModelShader = std::make_unique<Shader>("res/shaders/BasicLight.shader");

    // Camera View Set
    glfwSetWindowSizeCallback(m_GLFWWindow, &Window::window_size_callback);
    glfwSetScrollCallback(m_GLFWWindow, &Window::scroll_callback);
    glfwSetMouseButtonCallback(m_GLFWWindow, &Window::mouse_button_callback);
    glfwSetInputMode(m_GLFWWindow, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
    glfwSetCursorEnterCallback(m_GLFWWindow, &Window::cursor_enter_callback);
    glfwSetCursorPosCallback(m_GLFWWindow, &Window::cursor_position_callback);
    glfwSetKeyCallback(m_GLFWWindow, &Window::KeyCallback);

}

void Window::Draw(std::vector<Shape*>& shapes)
{

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    

    //Shapes Draw
    m_ModelShader->Bind();
    m_ModelShader->setUniformMat4f("u_Projection", m_Proj);
    m_ModelShader->setUniformMat4f("u_View", Window::camera.GetViewMatrix());
    m_ModelShader->setUniformVec3f("viewPos", Window::camera.GetPosition());
    //Light 
    m_ModelShader->setUniformVec3f("light.direction", glm::vec3(-0.2f, -1.0f, -0.3f));
    m_ModelShader->setUniformVec3f("light.diffuse", glm::vec3(0.5f,0.5f,0.5f));
    m_ModelShader->setUniformVec3f("light.ambient", glm::vec3(0.2f,0.2f,0.2f));
    m_ModelShader->setUniformVec3f("light.specular", glm::vec3(1.0f,1.0f,1.0f));

    for (int i = 0; i < shapes.size(); i++)
    {
        shapes[i]->OnRender(*m_ModelShader);
    }
    /* Swap front and back buffers */
    glfwSwapBuffers(m_GLFWWindow);

    /* Poll for and process events */
    glfwPollEvents();
    DoMovement();
}

Window::Window()
    :m_GLFWWindow(nullptr)

{

}

Window::~Window()
{
    glfwTerminate();
}

void Window::window_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    Window::m_Proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
}
void Window::cursor_position_callback(GLFWwindow* window, double xPos, double yPos)
{
    if (Window::entered_flag)
    {
        
            if (firstMouse)
            {
                lastx = xPos;
                lasty = yPos;
                firstMouse = false;
            }

            GLfloat xOffset = xPos - lastx;
            GLfloat yOffset = lasty - yPos;  // Reversed since y-coordinates go from bottom to left

            lastx = xPos;
            lasty = yPos;

            camera.ProcessMouseMovement(xOffset, yOffset);
        
    }
}
void Window::cursor_enter_callback(GLFWwindow* window, int entered)
{
    Window::entered_flag = entered;
}
void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (Window::entered_flag)
    {
        if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
        {
            Window::right_mouse_flag = 1;
        }
        else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
        {
            Window::right_mouse_flag = 0;
            Window::lastx = -1000.0;
            Window::lasty = -1000.0;
        }
        else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
        {
            Window::left_mouse_flag = 1;
        }
        else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
        {
            Window::left_mouse_flag = 0;
            Window::lastx = -1000.0;
            Window::lasty = -1000.0;
        }
    }
}
void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
    if (Window::entered_flag)
    {
        Window::camera.ProcessMouseScroll(yoffset);
    }
}


void Window::DoMovement()
{
    // Camera controls
    if (keys[GLFW_KEY_W] || keys[GLFW_KEY_UP])
    {
        Window::camera.ProcessKeyboard(FORWARD, 0.1);
    }

    if (keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN])
    {
        Window::camera.ProcessKeyboard(BACKWARD, 0.1);
    }

    if (keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT])
    {
        Window::camera.ProcessKeyboard(LEFT, 0.1);
    }

    if (keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT])
    {
        Window::camera.ProcessKeyboard(RIGHT, 0.1);
    }
}

// Is called whenever a key is pressed/released via GLFW
void Window::KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
    if (GLFW_KEY_ESCAPE == key && GLFW_PRESS == action)
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }

    if (key >= 0 && key < 1024)
    {
        if (action == GLFW_PRESS)
        {
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key] = false;
        }
    }
}



glm::mat4 Window::m_Proj = glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
int Window::entered_flag = 0;
int Window::right_mouse_flag=0;
int Window::left_mouse_flag=0;
double Window::lastx = 0, Window::lasty=0;
bool Window::firstMouse = true;
Camera Window::camera = Camera();
