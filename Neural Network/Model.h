
#pragma once

#include "Layer.h"
#include <iostream>
#include <fstream>

class Model {

public:
	void add(Layer* layer);
	void fit(int num_iterations);
	std::vector<float> predict(std::vector<float> X);
	void build();

private:
	std::vector<Layer *> model_layers;
};

