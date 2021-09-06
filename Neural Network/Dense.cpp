#include "Dense.h"
#include <iostream>

std::vector<float> Dense::forward(std::vector<float> input_array) {

    int num_outputs = weights.size() / input_array.size();

    int num_inputs = input_array.size();
    std::vector<float> output_array(num_outputs, 0.0);

    for (int i = 0; i < num_outputs; i++) {
        
        for (int j = 0; j < num_inputs; j++) {
            output_array[i] += weights[i + j] * input_array[j];
        }

        output_array[i] = layer_activation->activ(output_array[i] + Bias[i]);
    }

    return output_array;

}

std::vector<float> Dense::backward(std::vector<float> orig_delta, std::vector<float> next_layer_weights) {

    float dEtotal = 0.0;
    float delta_weight = 0.0;

    int num_hidden = num_neurons;
    std::vector<float> new_delta(num_neurons, 0.0);

    for (int i = 0; i < layer_output.size(); i++) {
    
        dEtotal = 0.0;

        for (int j = 0; j < orig_delta.size(); j++) {
            dEtotal += next_layer_weights[i + j] * orig_delta[j];
        }

        new_delta[i] = layer_activation->deriv(layer_output[i]) * dEtotal;

        for (int k = 0; k < layer_input.size(); k++) {
            delta_weight = (layer_input[k] * new_delta[i]) * epsilon;
            weights[i + k] -= delta_weight;
        }
        
        Bias[i] += (-1.0 * epsilon * new_delta[i]);

    }

    return new_delta;

}

Dense::Dense() {
}

Dense::Dense(int num_neurons_, Activation* A) {
    num_neurons = num_neurons_;
    layer_activation = A;
    Bias.resize(num_neurons_, 0.5);
}
