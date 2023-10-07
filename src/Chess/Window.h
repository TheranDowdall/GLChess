#pragma once

#include "Events/AppEvent.h"
#include "Events/MouseEvent.h"

struct GLFWwindow;

namespace CG{
    class Window{
        friend class GLFWCallbacks;
        
        struct MousePos{
            double x, y;
        };

        using EventCallbackFn = std::function<void(Event& e)>;
    public:
        struct WinProps{
            unsigned int width, height;
            std::string title;

            WinProps(unsigned int win_width = 1080, unsigned int win_height = 720, const std::string win_name = "Window")
            :width(win_width), height(win_height), title(win_name){}
        };
        
        Window(WinProps props = WinProps());
        ~Window();

        void OnUpdate();

        void setEventCallbackFunc(EventCallbackFn e) {windowData.eventCallback = e; }

        unsigned int getWidth() const {return windowData.winProps.width; }
        unsigned int getHeight() const {return windowData.winProps.height; }
        std::string getTitle() const {return windowData.winProps.title; }
        MousePos getMousePos() const {return windowData.mousePos; }

        void setBackgroundColour(float r, float g, float b, float a);

        static bool GLFWInited() {return s_GLFWInited; }
    private:
        bool Init();
        void Shutdown();
    private:
        GLFWwindow* m_window;

        struct WinData{
            WinProps winProps;
            MousePos mousePos;

            EventCallbackFn eventCallback;

            WinData(WinProps props)
            :winProps(props.width, props.height, props.title){}
        };
        WinData windowData;

        static bool s_GLFWInited;

        //Terminates GLFW if all windows are destroyed by the user
        static unsigned int s_GLFWActiveWindows;
    };
}