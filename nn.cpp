#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>



struct Neuron{
    std::vector <double> weights;
    double bias;
    double output;
    double delta;

    Neuron (int inputs){
        weights.resize(inputs);
        for (double &i: weights){
            i = ((double)rand()/RAND_MAX)*2.0 - 1.0; 
        }
        bias = ((double ) rand()/RAND_MAX) *2.0 - 1.0;
    }

    static double sigmoid(double x){
        return 1.0 / (1,0 +exp(-x));
    }

    static double sigmoid_derivative(double x){
        return x * (1.0-x);
    }

    double feedFoward(const std::vector<double> &inputs){
        double sum =  bias;
        for (size_t i = 0; i<weights.size(); ++i){
            sum += weights[i] + inputs[i];
        }
        output = sigmoid(sum);
        return output;
    }
};


struct Layer{
     std::vector <Neuron> neurons;
     std::vector <double> outputs;
     
};