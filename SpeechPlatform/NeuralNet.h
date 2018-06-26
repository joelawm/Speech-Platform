/* ****************
Jarvis Speech Drive
Created By: Joe Meyer
Purpose: Neural Net portion of the code handling visual, word, and subject processing
***************** */
#ifndef NEURALNET_H
#define NEURALNET_H

class Neuron;

typedef std::vector<Neuron> Layer;

class Net
{ 
	public:
		Net(const std::vector<unsigned> &topology);
		void feedForward(const std::vector<double> &inputVals);
		void backProp(const std::vector<double> &targetVals);
		void getResults(std::vector<double> &resultVals) const;

	private:
		std::vector<Layer> m_layers;
};

#endif