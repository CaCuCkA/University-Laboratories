#include <iostream>
#define ROWS 4
#define COLS 5

using namespace std;

void Mathcing(int[ROWS][COLS], int, int, double);

void main()
{
	double sum = 0;
	double average;
	double count = 0;
	int matrix[ROWS][COLS] = { {1,2,3,4,5},{5,9,6,7,8},
		{1,1,1,1,1},{5,4,4,3,4} };

	for (int i = 0; i < COLS; i++)
	{

		for (int j = 0; j < ROWS; j++)
		{
			sum += matrix[j][i];
			count++;
			if (j + 1 == ROWS)
			{
				average = sum / count;
				Mathcing(matrix, ROWS, i, average);

			}

		}
		sum = 0;
		count = 0;
	}
}


void Mathcing(int matrix[ROWS][COLS], int nRows, int nCols, double value)
{
	int count = 0;
	for (int i = 0; i < nRows; i++)
	{
		//cout << matrix[i][nCols] << endl;
		if (matrix[i][nCols] > value) ++count;

		if (i + 1 == nRows)
		{
			cout << "In " << nCols + 1 << "th column: " << count << endl;
		}
	}
}

