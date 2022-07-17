#include <iostream>

using namespace std;

int main(){
	int N, K, S;
	K = 0


	cout << "Enter N (N > 1): ";
	cin >> N;

	do{
	 	K++;
	 	S += K;


	} while(k < N);

	cout << "The smallest integer K for which the sum of 1 + 2 + ... + K is greater than or equal to N:" << K;
	return 0;
}
_____________________________________________________________

#include <iostream>

using namespace std;

int main(){
	int N, K, S;
	K = 0;


	cout << "Enter N (N > 1): ";
	cin >> N;
    while(K < N){
        
	 	K++;
	 	S += K;


	}

	cout << "The smallest integer K for which the sum of 1 + 2 + ... + K is greater than or equal to N:" << K;
	return 0;
}