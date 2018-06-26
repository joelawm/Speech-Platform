/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose:
***************** */
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include "UserInput.h"

using namespace std;

//constuctor
template<class T>
UserInput::UserInput() {}

//This takes the user input and send it to the take in
template<class T>
void UserInput::Input()
{
	cout << "User: ";

}

//Takein takes the infomation and formats it to english standards
template<class T>
void UserInput::TakeIn(char* InputFromUser)
{
	//Fromat it
	SeperateStringToChar(InputFromUser);
}

//Takes the formatted text form take in and sperates it into char
template<class T>
void UserInput::SeperateStringToChar(char* InputFromTakeIn)
{
	//using Strtok
	int i = 0;
	char *p = strtok(InputFromTakeIn, " ,-/"); //This includes delimiters to sperate from
	char *SentenceToChar[15]; //The actual array that items are being save to
	while (p != NULL)
	{
		SentenceToChar[i++] = p; //Appends Sentence to char
		p = strtok(NULL, " ,-/");
	}
}


