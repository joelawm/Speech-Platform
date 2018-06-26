/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose: This is for send commands to the Command Line
***************** */
#ifndef CLI_H
#define CLI_H
#include <iostream>
#include <string>
#include <queue>
#include <iterator>
#include "Settings.h"

//command line interface
namespace cli
{
	//Gives the Size of the string passed in
	int stringSize(std::string str)
	{
		std::stringstream s(str);
		std::string word;
		int count = 0;
		while (s >> word)
		{
			count++;
		}
		return count;
	}

	//prints out the command line line
	void printAccess()
	{
		Settings related;
		std::cout << related.Username << ": ";
	}
}

//This contains all speech related variables and functions
class Speech
{
	public:
		std::queue<std::string> userInput;
		std::queue<std::string> userInput2;
		std::queue<std::string> userInput3;
};
#endif