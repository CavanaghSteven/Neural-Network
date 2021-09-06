
#pragma once
#include "Layer.h"

class Output : public Layer {


public:
	std::vector<float> forward(std::vector<float>);
	std::vector<float> backward(std::vector<float>, std::vector<float>);

	Output();
	Output(int, Activation*);

private:

};

