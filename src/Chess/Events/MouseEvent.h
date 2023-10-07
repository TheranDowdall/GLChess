#pragma once 

#include "Event.h"

namespace CG{
    class MouseScrollEvent : public Event{
    public:
        MouseScrollEvent(double xOffset, double yOffseet)
        : m_x(xOffset), m_y(yOffseet){}

        ~MouseScrollEvent(){}

        double getxOffset() {return m_x; }
        double getyOffset() {return m_y; }
        
        EVENT_TYPE(MouseScrollEvent)
    private:
        double m_x, m_y;
    };

    class MouseMoveEvent : public Event{
    public:
        MouseMoveEvent(double xPos, double yPos)
        :m_xPos(xPos), m_yPos(yPos) {}

        ~MouseMoveEvent() {}

        double getxPos() {return m_xPos; }
        double getyPos() {return m_yPos; }

        EVENT_TYPE(MouseMoveEvent)
    private:
        double m_xPos, m_yPos;
    };

    class MouseButtonEvent : public Event{
    protected:
        MouseButtonEvent(int button)
        :m_button(button){}

        ~MouseButtonEvent(){}

        int getButton() {return m_button; }
    private:
        int m_button;
    };

    class MousePressEvent : public MouseButtonEvent{
    public:
        MousePressEvent(int button, double x, double y)
        : MouseButtonEvent(button), location(x, y){}
    
        ~MousePressEvent(){}

        double xPos() {return location.getxPos(); }
        double yPos() {return location.getyPos(); }
        EVENT_TYPE(MousePressEvent)
    private:
        MouseMoveEvent location;
    };

    class MouseReleaseEvent : public MouseButtonEvent{
    public:
        MouseReleaseEvent(int button)
        : MouseButtonEvent(button) {}

        ~MouseReleaseEvent(){}

        EVENT_TYPE(MouseReleaseEvent)
    };
}