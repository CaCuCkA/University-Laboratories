#include <iostream>

using namespace std;

void addLeftDigit(int D, int &K)
{
    int temp = K;
    K = 0;
    for(int step = 1; temp > 0; step*=10)
    {
        if (temp < 10) K += (temp%10)*step + D*step*10;
        else K += (temp%10)*step;
        temp /= 10;
    }

}

int main()
{
    int D1, D2, K;

    cout << "Input number: ";
    cin >> K;

    cout << "Input D1 and D2: ";
    cin >> D1 >> D2;
    addLeftDigit(D1, K);
    cout << "Number after adding D1: " << K << endl;
    addLeftDigit(D2, K);
    cout << "Number after adding D2: " << K << endl;

    return 0;
}
