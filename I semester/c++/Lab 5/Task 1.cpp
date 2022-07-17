#include <iostream>
#include <cmath>

using namespace std;

int sumRange(int A, int B)
{
    int sum = 0;
    if(A > B) return 0;
    else  sum = A + sumRange(A+1, B);
    return sum;
}

int main()
{
    int firstPoint, secondPoint, thirdPoint;

    cout << "Input first, second and third points: ";
    cin >> firstPoint >> secondPoint >> thirdPoint;


    cout << "Sum from first point to the second point: " << sumRange(firstPoint, secondPoint) << endl;
    cout << "Sum from second point to the third point: " << sumRange(secondPoint, thirdPoint) << endl;

    return 0;

}
