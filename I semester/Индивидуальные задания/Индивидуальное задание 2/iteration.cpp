#include <cmath>

const double min_value = 1e-5;

float factorial(int i)
{
  if (i==0) return 1;
  else return i*factorial(i-1);
}

double iteratedFunction(double x)
{
    double sum = 0;
    unsigned long step = 0;

    while(fabs(pow(x, step) / factorial(step)) >= min_value)
    {
        if(step == 0) sum += 1;
        else sum += (pow(x, step) / factorial(step));

        step++;
    }
    return sum;
}



double recursedFunction(double x, int k = 1)
{
    double result =  (pow(x, k) / factorial(k));

    if(result < min_value)
    {
        result = 1;
    }
    else
    {
        result += recursedFunction(x, k + 1);
    }
    return result;
}

