#include <iostream>

using namespace std;


int Product(int a, int b)
{
    int product = 1;
    for(int i = a; i <= b; i++){
        product *= i;

    }
    return product;
}

int main(){
    int A, B;

    cout << "Enter A: ";
    cin >> A;

    cout << "Enter B: ";
    cin >> B;

    cout << "Product: " << Product(A, B) << endl;

    return 0;
}
