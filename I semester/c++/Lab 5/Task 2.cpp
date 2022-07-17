#include <iostream>
#include <cmath>

using namespace std;

bool isSquare(int K)
{
    int number = sqrt(K);

    if(number*number == K) return true;
    else return false;
}

int main()
{
    int checkNumber;

    cout << "Input started position: ";
    cin >> checkNumber;

    for(int i = checkNumber; i < checkNumber + 10; i++)
    {
        cout << i << " - " << isSquare(i) << endl;
    }

    return 0;
}
