// Test_Callback.cpp : Defines the entry point for the application.
//

#include "Caller.h"

class TestObject
{
public:
	void testCallback(const std::string& args)
	{
		std::cout << "Test obj msg with arg: " << args << std::endl;
	}
};

int main()
{
	Caller caller;
	TestObject obj;

	std::cout << "Start" << std::endl;
	//obj.testCallback("test A");

	caller.registerCallback(&TestObject::testCallback, obj, "test A");

	caller.callCallback();

	std::cout << "End" << std::endl;

	return 0;
}
