#ifndef CALLER_H
#define CALLER_H

#include <iostream>
#include <functional>

class Caller
{
public:
	//template<class Callable, class ...argTypes>
	//void registerCallback(Callable&& callback, argTypes&& ...args)
	//{
	//	m_callbackFunc = std::bind(std::forward<Callable>(callback), std::forward<argTypes>(args...));
	//}

	template<typename Callable, typename... Args>
	void registerCallback(Callable&& callback, Args&& ... args) {
		// Store the callback function and its arguments
		m_callbackFunc = std::bind(callback, args...);
		//m_callbackFunc = std::bind(std::forward<Callable>(callback), std::forward<Args>(args...));
	}

	void callCallback() 
	{
		// Call the stored callback function
		if (m_callbackFunc) {
			m_callbackFunc();
		}
	}

private:
	std::function<void()> m_callbackFunc;
};

#endif \\ CALLER_H