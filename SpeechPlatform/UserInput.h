/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose: This takes the user input and tells the computer what you need it to do.
***************** */
#ifndef USERINPUT_H
#define USERINPUT_H
#include <iostream>
#include <sstream>
#include "CLINamespace.h"

//Functions
//emptys the queue after use
void empty()
{
	Speech SpeechC;
	SpeechC.userInput.empty();
}

//splits the string and saves it to a queue
void splitString(std::string ToSend)
{
	Speech SpeechC;
	std::istringstream iss(ToSend);

	//send string to stitch
	for (int i = 0; i < cli::stringSize(ToSend); i++)
	{
		std::string temp;
		iss >> temp;
		//retrun to be stitched together
		SpeechC.userInput.push(temp);
	}
}

//takes the user input, and displays lines
void UserInputTakeIn()
{
	//variable data
	std::string ToSend;

	//output the command line start
	cli::printAccess();

	//take in user input
	std::getline(std::cin, ToSend);

	//send the string to be split into words to send to a queue
	splitString(ToSend);
}
#endif