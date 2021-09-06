#include "Model.h"


void Model::add(Layer* layer) {
	model_layers.push_back(layer);
}

void Model::fit(int num_iterations) {

	Layer *layer;
	float loss = 0.0;
	std::vector<float> model_out(1, 0.0);
	std::vector<float> delta;
	std::vector<float> next_layer_weights;

	std::vector<float> X(1, 0.0);
	std::vector<float> y(1, 0.0);

	std::ofstream myfile;
	myfile.open("losses.csv");
	myfile << "Iteration,y,yhat\n";
	myfile.close();

	for (int iter = 0; iter < num_iterations; iter++) {

		X[0] =  (double)rand() / RAND_MAX;
		//y[0] = log(pow(X[0], 2));
		y[0] = sin(X[0]);

		// Feed through network, storing results for backpropagation later
		model_out = X;

		for (int l = 0; l < model_layers.size(); l++) {
			layer = model_layers[l];
			layer->set_input(model_out);
			model_out = layer->forward(model_out);
			layer->set_output(model_out);
		}

		// Perform back propagation

		// Output layer, needs different inputs
		delta = y;
		
		for (int j = model_layers.size(); j-- > 0; ) {

			layer = model_layers[j];
			delta = layer->backward(delta, next_layer_weights);

			next_layer_weights = layer->get_weights();
		}

		loss = pow((y[0] - model_out[0]), 2);

		std::cout << "Iteration " << y[0] << " " << model_out[0] << std::endl;

		myfile.open("losses.csv", std::ios_base::app);
		myfile << iter << "," << y[0] << "," << model_out[0] << "\n";
		myfile.close();

	}

}

std::vector<float> Model::predict(std::vector<float> X) {
	std::vector<float> temp(6, 0.0);
	return temp;
}

void Model::build() {

	std::vector<float> weights;
	Layer* current_layer;
	Layer* previous_layer;

	for (int i = 1; i < model_layers.size(); i++) {
		current_layer = model_layers[i];
		previous_layer = model_layers[i-1];

		weights.resize(current_layer->get_num_neurons() * previous_layer->get_num_neurons());
		current_layer->set_weights(weights);

	}

}
