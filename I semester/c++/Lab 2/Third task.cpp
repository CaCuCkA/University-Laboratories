#include <iostream>

using namespace std;

int main(){
	int A, B, C, N, K;

	cout << "Input A: ";
	cin >> A;

	cout << "Input B: ";
	cin >> B;

	cout << "Input C: ";
	cin >> C;

	if(!(A % 2)  || !(B % 2) || !(C % 2) ){
		N = A;
		K = B;
		A = (B + C) / 2;
		B = (N + C) / 2;
		C = (K + N) / 2;
	}
	else{
		A /= 2;
		B /= 2;
		C /= 2;
	}

	cout << "A: " << A << endl;
	cout << "B: " << B << endl;
	cout << "C: " << C << endl;

	return 0;
} 