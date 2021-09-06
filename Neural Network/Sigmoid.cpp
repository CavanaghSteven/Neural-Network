#include "Sigmoid.h"

float Sigmoid::deriv(float x) {
	float temp = activ(x);
	return temp * (1.0 - temp);
}


float Sigmoid::activ(float x) {
	return 1.0 / (1.0 + exp(-1.0 * x));
}
