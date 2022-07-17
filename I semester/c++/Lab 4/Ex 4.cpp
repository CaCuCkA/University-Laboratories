#include <iostream>

using namespace std;

int main()
{
    float X, N;


    cout << "Input X: ";
    cin  >> X;

    cout << "Input N: ";
    cin >> N;

    float sum = X, temp = 1, power = X;
    int factorial = 1;

    for(float i = 3; i <= 2*N + 1; i += 2)
    {
        cout << i << endl;

        factorial *= (i * (i - 1));
        cout << "Factorial: " << factorial << endl;

        power *= (X * X);
        cout << "Power: " << power << endl;

        temp *= -1 * (power / factorial);
        cout << "Temp: " << temp << endl;

        sum += temp;
        cout << "Sum: " << sum << endl;

        temp /= (power / factorial);

    }

    return 0;
}
