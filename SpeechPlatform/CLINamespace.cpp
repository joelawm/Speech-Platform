/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose: This is for send commands to the Command Line
***************** */
#include <iostream>
#include <string>
#include "Settings.h"

namespace cli
{
	class A
	{
		void printAccess()
		{
			Settings related;
			std::cout << related.Username << ": ";
		}
	};
}