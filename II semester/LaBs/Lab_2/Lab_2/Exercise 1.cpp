#include <iostream>
#define ROWS 4
#define COLS 5

using namespace std;

void main() 
{
	int matrix[ROWS][COLS];

	int K;
	
	cout << "Input K: ";
	cin >> K;

	cout << "Matrix: " << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			matrix[i][j] = K * i;
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}


}