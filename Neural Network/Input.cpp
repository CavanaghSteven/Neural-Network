#include "Input.h"

#include <iostream>

std::vector<float> Input::forward(std::vector<float> input_array) {
    return input_array;
}

std::vector<float> Input::backward(std::vector<float> delta, std::vector<float> nlw) {
    return delta;
}

Input::Input(int num_neurons_) {
    num_neurons = num_neurons_;
}
