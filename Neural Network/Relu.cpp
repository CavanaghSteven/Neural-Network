#include "Relu.h"

float Relu::deriv(float x) {

	if (x <= 0) {
		return 0;
	}
	else {
		return 1;
	}

}

float Relu::activ(float x) {

	if (x <= 0) {
		return 0.01 * x;
	}
	else {
		return x;
	}

}