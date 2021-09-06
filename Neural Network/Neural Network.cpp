// Neural Network.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Model.h"
#include "Dense.h"
#include "Output.h"
#include "Sigmoid.h"
#include "Relu.h"
#include "Input.h"


int main() {

    std::vector<int> num_neurons = { 512, 512, 512 };
    Model nn_model;
    int num_iterations = 1000000;

    Relu relu_activate;
    Sigmoid sigmoid_activate;

    Input in(1);
    Dense first(num_neurons[0], &sigmoid_activate);
    Dense second(num_neurons[1], &sigmoid_activate);
    Dense third(num_neurons[2], &sigmoid_activate);
    Output out(1, &sigmoid_activate);

    nn_model.add(&in);
    nn_model.add(&first);
    nn_model.add(&second);
    nn_model.add(&third);
    nn_model.add(&out);

    nn_model.build();

    nn_model.fit(num_iterations);

    std::cout << "Program Ended Sucessfully" << std::endl;
}
