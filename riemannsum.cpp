#include "riemannsum.h"

double
integrate(std::vector<double> x, std::vector<double> y,
          double bound1, double bound2){

    long unsigned index1 = indexOf(x, bound1);
    double integration = 0;
    for (unsigned long i = index1; x[i] < bound2; i++)
        integration += ((y[i] + y[i + 1]) / 2.0) * ( x[i + 1] - x[i]);


    return integration;
}

unsigned long
indexOf(std::vector<double> x, double element){

    unsigned long startingPoint = 0;
    unsigned long endPoint = x.size() - 1;
    unsigned long midPoint = 0;

    for(int i = 0; i < 10; i++){

        midPoint = (startingPoint + endPoint) / 2;
        if (x[midPoint] > element){
            endPoint = midPoint;
        } else if (x[midPoint] < element) {
            startingPoint = midPoint;
        } else {
            return midPoint;
        }
    }
    return midPoint;
}
