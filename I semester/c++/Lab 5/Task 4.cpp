#include <iostream>

using namespace std;

void shiftLeft(int A, int B, int C)
{
    int temp = 0;
    temp = A;
    A = B;
    B = C;
    C = temp;
    cout << "First number = " << A << endl << "Second number = " << B << endl << "Third number = " << C << endl;
}


int main()
{
    int FirstNumGroupOne, SecondNumGroupOne, ThirdNumGroupOne;
    int FirstNumGroupTwo, SecondNumGroupTwo, ThirdNumGroupTwo;

    cout << "Input numbers for the second group: ";
    cin >> FirstNumGroupOne >> SecondNumGroupOne >> ThirdNumGroupOne;
    shiftLeft(FirstNumGroupOne, SecondNumGroupOne, ThirdNumGroupOne);

    cout << "Input numbers for the second group: ";
    cin >> FirstNumGroupTwo >> SecondNumGroupTwo >> ThirdNumGroupTwo;
    shiftLeft(FirstNumGroupTwo, SecondNumGroupTwo, ThirdNumGroupTwo);


    return 0;
}
