/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose: This is the start of something beautiful
***************** */
#include <stdlib.h>
#include <thread>
#include <vector>
#include "UserInput.h"
#include "Settings.h"
#include "NeuralNet.h"

//start the neural network
void startNeuralNet()
{
	std::vector<unsigned> topology;
	std::vector<double> inputVals;
	std::vector<double> targetVals;
	std::vector<double> resultVals;
	Net myNet(topology);
	//feeding info
	myNet.feedForward(inputVals);
	//outputs for learning
	myNet.backProp(targetVals);
	//displays results
	myNet.getResults(resultVals);
}

int main()
{
	Settings system;
	while (system.Running == true)
	{
		//start threading
		std::thread worker(startNeuralNet);
		std::thread PythonCommunication();
		worker.join(); //wait for it to finish work
		std::cout << "Threads have been loaded\n";

		UserInputTakeIn();
	}
	return 0;
}