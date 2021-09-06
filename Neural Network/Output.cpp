
#include "Output.h"
#include <iostream>

std::vector<float> Output::forward(std::vector<float> input_array) {

    int num_outputs = weights.size() / input_array.size();
    int num_inputs = input_array.size();
    std::vector<float> output_array(num_outputs, 0.0);

    for (int i = 0; i < num_outputs; i++) {

        for (int j = 0; j < num_inputs; j++) {
            output_array[i] += weights[i+j]*input_array[j];
        }
        output_array[i] = layer_activation->activ(output_array[i] + Bias[i]);
    }

    return output_array;
}

std::vector<float> Output::backward(std::vector<float> desired_output, std::vector<float> nlw) {

    float output = 0.0;
    std::vector<float> delta(num_neurons, 1.0);
    float delta_weight = 0.0;

    // Loop over all output units
    for (int i = 0; i < layer_output.size(); i++) {
        
        output = layer_output[i];
        //delta[i] = pow(-(desired_output[i] - output), 2) * layer_activation->deriv(output);
        delta[i] = pow(output - desired_output[i], 2) * layer_activation->deriv(output);

        // Update each connection to the output unit
        for (int j = 0; j < layer_input.size(); j++) {
            
            delta_weight = (delta[i] * layer_input[j]) * epsilon;
            // Update the weights
            weights[i+j] -= delta_weight;
        }

        // Update the Bias
        Bias[i] -= epsilon * delta[i];

    }

    return delta;

}

Output::Output() {
}

Output::Output(int num_neurons_, Activation* A) {
    num_neurons = num_neurons_;
    layer_activation = A;
    Bias.resize(num_neurons_, 0.5);
}
