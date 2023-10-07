#pragma once

namespace CG{
    //To be called under the public access modifier in any child class of Event
    #define EVENT_TYPE(x)\
    bool DispatchEvent() override { return EventCallback(NULL, this); }\
    static void setCallback(EventFn<x> func) { EventCallback(func, nullptr); }\
    private:\
    static bool EventCallback(EventFn<x> func, x* e){\
        static EventFn<x> callback;\
        if(callback != NULL)\
            return callback(*e);\
        else if(func != NULL)\
            callback = func;\
        else\
            return true;\
        return false;\
    };

    class Event{
    protected:
        template <typename T>
        using EventFn = std::function<bool(T&)>;
    public:
        virtual bool DispatchEvent() = 0;
    };
}