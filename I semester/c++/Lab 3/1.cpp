#include <iostream>

using namespace std;

int main(){
	int A, B, C;

	int amount_A = 0, amount_B = 0;

	cout << "Enter A: ";
	cin >> A;

	cout << "Enter B: ";
	cin >> B;

	cout << "Enter C: ";
	cin >> C;


	while(A >= C){
		A -= C;
		while (B>= C){
			++amount_B;
			B -= C;
		}
		amount_A += amount_B;
	}

	cout << "Amount of squares in rictangle: " << amount_A << endl;
	return 0;
}
