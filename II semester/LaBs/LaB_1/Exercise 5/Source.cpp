#include <iostream>
#define N 10

using namespace std;



int main()
{
	int array[N] = { 1, 2, 3, 4, 4, 5, 5, 6, 6, 7};
	int count;

	for (int i = 1, count = 0; i < N; i++)
	{
		if (array[i] < array[i - 1] && array[i] < array[i + 1])
		{
			count++;
		}
		if (i == N - 1)
		{
			cout << "_____________________________________" << endl;
			cout << "Count: " << count << endl;
		}
	}
	
	return 0;
}