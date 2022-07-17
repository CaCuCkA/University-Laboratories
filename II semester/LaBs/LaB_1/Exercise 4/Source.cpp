#include <iostream>
#define N 10

using namespace std;


int main()
{
	int array[N] = { 9, 8, 6, 10, 5, 4, 3, 2, 1, 0 };


	for (int i = 0; i < N; i++)
	{
		if (array[i + 1] > array[i])
		{
			cout << "_____________________________________" << endl;
			cout << "Number: " << array[i + 1] << endl;
			cout << "Index: " << i + 1 << endl;
			break;
		}
		if (i == N - 1) cout << "1" << endl;
	}
	return 0;
}
