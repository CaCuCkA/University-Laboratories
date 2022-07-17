#include <iostream>

using namespace std;

void shiftLeft(int *A, int *B, int *C)
{
    int temp = 0;
    temp = *A;
    *A = *B;
    *B = *C;
    *C = temp;

}


int main()
{
    int FirstNumGroupOne, SecondNumGroupOne, ThirdNumGroupOne;
    int FirstNumGroupTwo, SecondNumGroupTwo, ThirdNumGroupTwo;

    cout << "Input numbers for the second group: ";
    cin >> FirstNumGroupOne >> SecondNumGroupOne >> ThirdNumGroupOne;
    shiftLeft(&FirstNumGroupOne, &SecondNumGroupOne, &ThirdNumGroupOne);
    cout << "First number = " << FirstNumGroupOne << endl << "Second number = " << SecondNumGroupOne << endl << "Third number = " << ThirdNumGroupOne << endl;

    cout << "Input numbers for the second group: ";
    cin >> FirstNumGroupTwo >> SecondNumGroupTwo >> ThirdNumGroupTwo;
    shiftLeft(&FirstNumGroupTwo, &SecondNumGroupTwo, &ThirdNumGroupTwo);
    cout << "First number = " << FirstNumGroupTwo << endl << "Second number = " << SecondNumGroupTwo << endl << "Third number = " << ThirdNumGroupTwo << endl;


    return 0;
}
