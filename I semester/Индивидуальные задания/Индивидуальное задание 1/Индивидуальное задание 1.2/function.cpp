#include <cmath>

double ValueX(double f){
    return floor(asin(sqrt(f - 1)) * 100) / 100;
}

