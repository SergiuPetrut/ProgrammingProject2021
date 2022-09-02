#include <math.h>
#include "functions_header.h"
float sigmoid(float x){
    float result;

    result = 1/(1+expf(-x));
    return result;
}
float sigmoid_derivative(float x){
    float result;
    result = sigmoid(x)*(1 - sigmoid(x));
    return result;

}
void trainer (double tr
[][3], double troutput[], int q, double weights[3])
    {

        double output[4];
        double error[4];
        double tranput[3][4];
        for (int i = 0; i < q; i++)
        {
            output[0] = sigmoid(dot_product(trinput[0], weights, 3)); //First run
            output[1] = sigmoid(dot_product(trinput[1], weights, 3));
            output[2] = sigmoid(dot_product(trinput[2], weights, 3));
            output[3] = sigmoid(dot_product(trinput[3], weights, 3));
            error[0]=(troutput[0]- output[0])*sigmoid_derivative(output[0]); //Errors
            error[1]=(troutput[1]- output[1])*sigmoid_derivative(output[1]);
            error[2]=(troutput[2]- output[2])*sigmoid_derivative(output[2]);
            error[3]=(troutput[3]- output[3])*sigmoid_derivative(output[3]);
            for(int j = 0; j < 3; j++)
            {
                for(int y = 0; y < 4; y++){
                    tranput[j][y] = trinput[y][j];
                }
            }
            //Applying margins to weights
            weights[0] += dot_product(tranput[0], error, 4);
            weights[1] += dot_product(tranput[1], error, 4);
            weights[2] += dot_product(tranput[2], error, 4);
        }

    }

double dot_product( double *v1, double *v2, int size){
    double result = 0;

    for (int i = 0; i < size; i++)
    {
        result+= v1[i]*v2[i];
    }
    return result;

}

double anal(double input[], double weights[3]){
    double result = dot_product(input, weights, 3);
    return sigmoid(result);
}
