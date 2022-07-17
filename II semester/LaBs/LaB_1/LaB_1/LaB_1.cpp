#include <iostream>
#define size 100

using namespace std;

int main() 
{
	int N;
	double F1 = 0, F2 = 1, temp;
	double array[size];

	cout << "Input N: ";
	cin >> N;


	

	for (int i = 2; i < N; i++)
	{
		temp = F2;
		F2 += F1;
		F1 = temp;
		array[i] = F2;
		cout << i + 1 << "th element in lenght: " << array[i] << endl;
	}


	return 0;
	
}