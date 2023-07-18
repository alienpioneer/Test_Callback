#ifndef CALLER_H
#define CALLER_H

#include <iostream>
#include <functional>

class Caller
{
public:
    template<typename Callable, typename... Args>
    void registerCallback(Callable&& callback, Args&& ... args) {
        // Store the callback function and its arguments
        m_callback = std::bind(std::forward<Callable>(callback), std::forward<Args>(args)...);

        //std::function<typename std::result_of<Callable(Args...)>::type()> task = std::bind(std::forward<Callable>(callback), std::forward<Args>(args)...);
        //task();
    }

    void unregisterCallback()
    {
        m_callback = nullptr;
    }

    void execute()
    {
        if (m_callback.target_type().name() != typeid(void).name())
            m_callback();
        else
            std::cout << "No valid callback !\n";
    }

private:
    std::function<void()> m_callback;
};

#endif \\ CALLER_H