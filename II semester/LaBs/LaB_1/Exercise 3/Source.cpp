#include <iostream>
#define N 11

using namespace std;

int main()
{
	int array[N];


	for (int i = 0; i < N; i++)
	{
		cout << "Enter " << i + 1 << "th number: " << endl;
		cin >> array[i];
	}


	for (int i = N - 2; i > 0; i-=2)
	{
		cout << "_____________________________________" << endl;
		cout << "Number: " << array[i] << endl;
		cout << "Index: " << i << endl;
		
	}
	return 0;

}