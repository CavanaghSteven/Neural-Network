#include "Layer.h"

void Layer::set_weights(std::vector<float> in_weights) {
	weights = in_weights;
}

std::vector<float> Layer::get_weights() {
	return weights;
}

int Layer::get_num_neurons() {
	return num_neurons;
}

void Layer::set_input(std::vector<float> layer_in) {
	layer_input = layer_in;
}

void Layer::set_output(std::vector<float> layer_out) {
	layer_output = layer_out;
}

