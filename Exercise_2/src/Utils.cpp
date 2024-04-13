#include <iostream>
#include "Utils.hpp"
using namespace std;
double prodottoscalarepesato (double* p1, double* p2, int n, double S){
    double somma=0;
    for (int i=0; i<n; i++){
        double a=(*(p1+i))*S;
        double b=(*(p2+i))+1;
        somma=somma + a*b;
    }
    return somma;
}
