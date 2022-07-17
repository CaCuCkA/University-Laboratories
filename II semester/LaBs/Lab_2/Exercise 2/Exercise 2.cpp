#include <iostream>
#define ROWS 4
#define COLS 5


using namespace std;

//void Initialize(int[ROWS][COLS], int, int);

void main()
{
	int matrix[ROWS][COLS];
	int borderC, borderP;
	int sum = 0;

	//Initialize(matrix, ROWS, COLS);
	

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{												// RANDOM INITIALIZING 
			matrix[i][j] = rand() % 10;
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "Matrix is full" << endl;

	cout << "Enter value for borders (c, p): ";			// ENTERING VALUES FOR BORDERS
	cin >> borderC >> borderP;


	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (matrix[i][j] % 2 == 0)
			{
				if (matrix[i][j] < borderC || borderP < matrix[i][j])		// CHECK OCCURENCE
				{
					//cout << matrix[i][j] << endl;
					sum += matrix[i][j];
				}
			}
		}
	}
	cout << "Sum: " <<  sum << endl;


}





/*
void Initialize(int matrix[ROWS][COLS], int nRows, int nCols)
{
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			cout << "Enter value for element in " << i << "th row and " << j << "th collum: ";
			cin >> matrix[i][j];
		}
	}
}
*/
