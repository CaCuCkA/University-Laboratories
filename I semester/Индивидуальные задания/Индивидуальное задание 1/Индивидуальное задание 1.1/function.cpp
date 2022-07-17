#include <cmath>

double f(double x){
    return pow(sin(x), 2) + 1;
}


double RightTriangle(double a, double b, int n){
    double h = (b - a) / n;
    double sum = 0.0;
    for (int i = 1; i <= n; i++){
        sum += h * f(a + i * h);
    }
    return sum;
}
