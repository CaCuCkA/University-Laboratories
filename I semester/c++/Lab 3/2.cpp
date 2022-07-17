#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, K;

	cout << "Enter N (N > 1): ";
	cin >> N;

	K = 0;
	while(pow(3, K) < N){
		++K;
		cout << "Degree K increased by 1" <<endl;
	}

	cout << "Degree K = " << K << endl;
	return 0;
}
_____________________________________________________________________

#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int N, K;

	cout << "Enter N (N > 1): ";
	cin >> N;

	K = 0;
	
	do{
	    ++K;
		cout << "Degree K increased by 1" <<endl;
	}
	while(pow(3, K) < N);

	cout << "Degree K = " << K << endl;
	return 0;
}