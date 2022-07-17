#include <iostream>

using namespace std;

int addLeftDigit(int D, int K)
{
    int temp = K;
    K = 0;
    for(int step = 1; temp > 0; step*=10)
    {
        if (temp < 10) K += (temp%10)*step + D*step*10;
        else K += (temp%10)*step;
        temp /= 10;


    }
    return K;
}

int main()
{
    int D1, D2, K;

    cout << "Input number: ";
    cin >> K;

    cout << "Input D1 and D2: ";
    cin >> D1 >> D2;

    cout << "Number after adding D1: " << addLeftDigit(D1, K) << endl;
    cout << "Number after adding D2: " << addLeftDigit(D2, addLeftDigit(D1, K)) << endl;

    return 0;
}
