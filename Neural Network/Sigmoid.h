#pragma once
#include "Activation.h"
class Sigmoid : public Activation {

public:
	float deriv(float);
	float activ(float);

private:

};

