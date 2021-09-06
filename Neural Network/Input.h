#pragma once
#include "Layer.h"
class Input : public Layer {

public:
	std::vector<float> forward(std::vector<float>);
	std::vector<float> backward(std::vector<float>, std::vector<float>);

	Input(int);

private:

};

