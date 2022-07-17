#include <iostream>

using namespace std;

void Power(int a, int b)
{
    int sum = 1;
    cout << "A (" << a << ") to degree (0) :" << sum << endl;
    for(int i = 0; i < b; i++){
        sum *= a;
        cout << "A (" << a << ") to degree (" << i + 1 << ") :" << sum << endl;
    }
}

int main(){
    int A, N;

    cout << "Input A: ";
    cin >> A;

    cout << "Input N (N > 0): ";
    cin >> N;

    Power(A, N);

    return 0;

}
