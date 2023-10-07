#include "cgpch.h"

#include "GLFWCallbacks.h"

namespace CG{
    bool Window::s_GLFWInited = false;
    unsigned int Window::s_GLFWActiveWindows = 0;

    Window::Window(WinProps props)
    : windowData(props){
        if(!Init()){
            std::cout << "ERROR: Failed to create application window" << std::endl;
        } 
    }

    Window::~Window(){
        Shutdown();
    }

    bool Window::Init(){
        if(!s_GLFWInited){
            
            if(!glfwInit())
                return false;
            
            s_GLFWInited = true;
            glfwSetErrorCallback(GLFWCallbacks::OnError);
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_DEPTH_BITS, GL_TRUE);
        
        m_window = glfwCreateWindow(windowData.winProps.width, windowData.winProps.height, 
                                    windowData.winProps.title.c_str(), NULL, NULL);
        glfwMakeContextCurrent(m_window);
        glfwSetWindowUserPointer(m_window, &windowData);

        glfwSetWindowCloseCallback(m_window, GLFWCallbacks::OnWindowClose);
        glfwSetWindowSizeCallback(m_window, GLFWCallbacks::OnWindowResize);
        glfwSetScrollCallback(m_window, GLFWCallbacks::OnMouseScroll);
        glfwSetCursorPosCallback(m_window, GLFWCallbacks::OnMouseMove);
        glfwSetMouseButtonCallback(m_window, GLFWCallbacks::OnMouseEvent);
        
        s_GLFWActiveWindows++;

        return true;
    }

    void Window::Shutdown(){
        glfwDestroyWindow(m_window);

        s_GLFWActiveWindows--;
        if(s_GLFWActiveWindows == 0){
            glfwTerminate();
            s_GLFWInited = false;
        }
    }

    void Window::setBackgroundColour(float r, float g, float b, float a){
        glClearColor(r, g, b, a);
    }

    void Window::OnUpdate(){
        glfwSwapBuffers(m_window);
        glfwPollEvents();
    }

    bool getGLFWInit() {return Window::GLFWInited(); }
}