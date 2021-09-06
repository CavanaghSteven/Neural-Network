#pragma once

#include <math.h>

class Activation {

public:
	virtual float deriv(float) = 0;
	virtual float activ(float) = 0;
};

