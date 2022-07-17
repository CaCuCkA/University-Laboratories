#include <iostream>
#define ROWS 4
#define COLS 5

using namespace std;

void maxValueForRows(int[ROWS][COLS], int, int, int);
void minValueForColumns(int[ROWS][COLS], int, int, int);

//void deleteMatrixValue(int[ROWS][COLS], int, int);
//void Initialize(int[ROWS][COLS], int, int);

void main()
{
	int matrix[ROWS][COLS];
	int minValue = 100, maxValue = 0;

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

	cout << "===========================================================" << endl;
	maxValueForRows(matrix, ROWS, COLS, maxValue);
	cout << "===========================================================" << endl;
	minValueForColumns(matrix, ROWS, COLS, minValue);
	cout << "===========================================================" << endl;
	//deleteMatrixValue(matrix, ROWS, COLS);

	
}







void maxValueForRows(int matrix[ROWS][COLS], int nRows, int nCols, int value)
{
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			if (matrix[i][j] > value) value = matrix[i][j];
		}
		cout << "Max value for " << i << "th row: " << value << endl;
		value = 0;
	}
}

void minValueForColumns(int matrix[ROWS][COLS], int nRows, int nCols, int value)
{
	for (int i = 0; i < nCols; i++)
	{
		for (int j = 0; j < nRows; j++)
		{
			if (matrix[j][i] < value) value = matrix[j][i];
		}
		cout << "Min value for " << i << "th column: " << value << endl;
		value = 100;
	}
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

/*
void deleteMatrixValue(int matrix[ROWS][COLS], int nRows, int nCols)
{
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
}
*/