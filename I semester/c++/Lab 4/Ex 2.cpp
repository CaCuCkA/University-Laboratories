#include <iostream>

using namespace std;

int main()
{
    int N;


    cout << "Input N (N > 0): ";
    cin >> N;

    int s = N * N, m = -1;

    for(int i=N + 1; i < 2*N + 1; ++i){
        m *= -(i * i);
        s += m;
        m = m / (i * i);
    }
    cout << s << endl;
    return 0;
}
