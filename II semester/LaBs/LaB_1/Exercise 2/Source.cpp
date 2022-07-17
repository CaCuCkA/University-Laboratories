#include <iostream>
#define N 10

using namespace std;

int main() 
{
	double array[N];
	int count, P;
	
	cout << "Please input 10 numbers for array: " << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter " << i + 1 << "th number: " << endl;
		cin >> array[i];
	}
	cout << "--------------------------------------------------" << endl;

	cout << "Input P: ";
	cin >> P;
	cout << "--------------------------------------------------" << endl;

	for (int i = 0, count = 0; i < 10; i++)
	{
		if (array[i] > P)
		{
			cout << "Posive number: " << array[i] << endl << "Index: " << i << endl;
			cout << "--------------------------------------------------" << endl;
			count++;
		}
		
	}
	cout << "Count of numbers: " << count << endl;

	
	return 0;
}