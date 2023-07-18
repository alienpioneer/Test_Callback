// Test_Callback.cpp : Defines the entry point for the application.
//

#include "Caller.h"

class TestObject
{
public:
	void testCallbackA(const std::string& args)
	{
		std::cout << "Test obj msg with str arg: " << args << "\n";
	}

	void testCallbackB(int arg1, int arg2)
	{
		std::cout << "Test obj msg with numeric arg: " << arg1 << " " << arg2 << "\n";
	}
};

int main(int argc, char** argv)
{
	Caller caller;
	TestObject obj;

	std::cout << "Start" << "\n";

	caller.registerCallback(&TestObject::testCallbackA, obj, "StrArg");
	caller.execute();

	caller.registerCallback(&TestObject::testCallbackB, obj, 31, 42);
	caller.execute();

	caller.unregisterCallback();
	caller.execute();

	std::cout << "End" << "\n\n\n";
}