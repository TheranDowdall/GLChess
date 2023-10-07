#pragma once

#include "Event.h"

namespace CG{
    class WindowCloseEvent : public Event{
    public:
        WindowCloseEvent(){}
        ~WindowCloseEvent(){}

        EVENT_TYPE(WindowCloseEvent);
    };

    class WindowResizeEvent : public Event{
    public:
        WindowResizeEvent(unsigned int Width, unsigned int Height)
        : m_width(Width), m_height(Height){}

        ~WindowResizeEvent(){}

        unsigned int getWidth() {return m_width; }
        unsigned int getHeight() {return m_height; }

        EVENT_TYPE(WindowResizeEvent);
    private:
        unsigned int m_width, m_height;
    };
}