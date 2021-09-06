#pragma once
#include "Layer.h"

class Dense : public Layer{

public:
	std::vector<float> forward(std::vector<float>);
	std::vector<float> backward(std::vector<float>, std::vector<float>);

	Dense();
	Dense(int, Activation*);

private:

};

