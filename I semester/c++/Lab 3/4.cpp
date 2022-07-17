#include <iostream>

using namespace std;

int main(){
	int N, M, place = 1, new_number = 0;

	cout << "Enter your number: ";
	cin >> N;

	cout << "Enter a number which you want to delete (from 0 to 9): ";
	cin >> M;

	do{
		if((N % 10) % M != 0){
			new_number += N % 10 * place;
			place *= 10;
		}
		N /= 10;

	}
	while(N > 0);

	cout << "Final result: " << new_number << endl;
	return 0;
}

_______________________________________________________________________________

#include <iostream>

using namespace std;

int main(){
	int N, M, place = 1, new_number = 0;

	cout << "Enter your number: ";
	cin >> N;

	cout << "Enter a number which you want to delete (from 0 to 9): ";
	cin >> M;

	while(N > 0){
		if((N % 10) % M != 0){
			new_number += N % 10 * place;
			place *= 10;
		}
		N /= 10;

	}

	cout << "Final result: " << new_number << endl;
	return 0;
}



for(;;){