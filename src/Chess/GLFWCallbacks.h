#pragma once 

#include "Window.h"

#include <GLFW/glfw3.h>

namespace CG{
    class GLFWCallbacks{
    public:
        static void OnError(int error_code, const char* description){
                std::cout << "GLFW ERROR(" << error_code << "): " << description << std::endl;
        }

        static void OnWindowClose(GLFWwindow* m_window){
            Window::WinData data = *(Window::WinData*)glfwGetWindowUserPointer(m_window);

            WindowCloseEvent e;
            data.eventCallback(e);
        }

        static void OnWindowResize(GLFWwindow* m_window, int width, int height){
            Window::WinData* data = (Window::WinData*)glfwGetWindowUserPointer(m_window);

            glViewport(0, 0, width, height);

            data->winProps.width = width;
            data->winProps.height = height;

            WindowResizeEvent e = WindowResizeEvent(width, height);
            data->eventCallback(e);
        }

        static void OnMouseScroll(GLFWwindow* m_window, double x, double y){
            Window::WinData* data = (Window::WinData*)glfwGetWindowUserPointer(m_window);
            
            MouseScrollEvent e = MouseScrollEvent(x, y);
            data->eventCallback(e);   
        }

        static void OnMouseMove(GLFWwindow* m_window, double x, double y){
            Window::WinData* data = (Window::WinData*)glfwGetWindowUserPointer(m_window);
            data->mousePos.x = x;
            data->mousePos.y = data->winProps.height - y;

            MouseMoveEvent e = MouseMoveEvent(data->mousePos.x, data->mousePos.y);
            data->eventCallback(e);   
        }

        static void OnMouseEvent(GLFWwindow* m_window, int button, int action, int mods){
            Window::WinData* data = (Window::WinData*)glfwGetWindowUserPointer(m_window);

            if(action == GLFW_PRESS || action == GLFW_REPEAT){
                MousePressEvent e = MousePressEvent(button, data->mousePos.x, data->mousePos.y);
                data->eventCallback(e);
            }
            else{
                MouseReleaseEvent e = MouseReleaseEvent(button);
                data->eventCallback(e); 
            }  
        }
    };
}