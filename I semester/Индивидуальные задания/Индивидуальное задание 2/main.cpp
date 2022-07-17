#include <iostream>
#include <cmath>
#include "function.h"

using namespace std;



double checkingFunction(double x)
{
    return exp(x);
}

int main(){

    int amount_of_steps;
    double initial_border, final_border;
    double difference;


    cout << "Enter initial and final borders: ";
    cin >> initial_border >> final_border;

    cout << "Enter amount of steps: ";
    cin >> amount_of_steps;

    difference = (final_border - initial_border) / amount_of_steps;

    for(int i = 1; i <= amount_of_steps + 1; i++)
    {
        cout << i << "." << '\t' << initial_border << '\t' << iteratedFunction(initial_border) << '\t';
        cout << '\t' << checkingFunction(initial_border) << '\t' << '\t' << recursedFunction(initial_border) << endl;
        initial_border += difference;
    }

/**
    cout << "Errors: " << endl;

   for(int i = 1; i <= amount_of_steps + 1; i++)
    {
        cout << i << "." << '\t' << initial_border << '\t' << checkingFunction(initial_border) - iteratedFunction(initial_border) << '\t';
        cout  <<  checkingFunction(initial_border) - recursedFunction(initial_border) << endl;
        initial_border += difference;
    }
**/
    return 0;

}
