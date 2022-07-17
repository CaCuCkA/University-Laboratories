#include <iostream>

using namespace std;

int main()
{
    float N, temp_A = 0, A = 1;

    cout << "Input N (N > 0): ";
    cin >> N;

    for(float k = 1;  k < N + 1; k++){
        temp_A = A;
        A = (temp_A + 1) / k;
        cout << "A = " << A <<", when K = " << k << endl;

    }
    return 0;
}

