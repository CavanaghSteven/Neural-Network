#pragma once
#include "Activation.h"
class Relu : public Activation {

public:
	float deriv(float);
	float activ(float);

private:

};

