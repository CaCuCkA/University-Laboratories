#include <iostream>

using namespace std;

int main(){
	int N, K = 2;
	int f1 = 0, f2 = 1, f;

	cout << "Enter N (N is Fiabonicci number): ";
	cin >> N;

	while(f != N){

		f = f1 + f2;
		f1 = f2;
		f2 = f;
		K++;
	}
	cout << "Sequential number of the number " << N <<" equels: " << K << endl;
	return 0;
}

___________________________________________________________________________________

#include <iostream>

using namespace std;


int main(){
	int N, K = 2;
	int f1 = 0, f2 = 1, f;

	cout << "Enter N (N is Fiabonicci number): ";
	cin >> N;

	do{

		f = f1 + f2;
		f1 = f2;
		f2 = f;
		K++;
	}
	
	while(f != N);
	
	cout << "Sequential number of the number " << N <<" equels: " << K << endl;
	return 0;
}