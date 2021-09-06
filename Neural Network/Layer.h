#pragma once

#include "Activation.h" 
#include <vector>

class Layer {

public:
	virtual std::vector<float> forward(std::vector<float>) = 0;
	virtual std::vector<float> backward(std::vector<float>, std::vector<float>) = 0;

	void set_input(std::vector<float>);
	void set_output(std::vector<float>);

	void set_weights(std::vector<float>);

	std::vector<float> get_weights();

	int get_num_neurons();

protected:
	int num_neurons = 0;
	float epsilon = 0.001;
	std::vector<float> layer_input;
	std::vector<float> layer_output;
	std::vector<float> weights;
	std::vector<float> Bias;
	Activation* layer_activation;
};

