#include <iostream>
#define ROWS 4
#define COLS 5

using namespace std;

void main()
{
	int matrix[ROWS][COLS] = { {1,2,3,4,5},{5,6,6,7,8},
		{1,1,1,1,1},{5,4,4,3,4}};

	int count = ROWS;
	int stop;
	
	for (int i = 0; i < ROWS; i++)
	{
		stop = 0;
		for (int j = 0; j < COLS && !stop; j++)
		{
			for (int k = j + 1; k < COLS; k++)
			{
				//cout << matrix[i][j] << " " << matrix[i][k] << endl;
				if (matrix[i][j] == matrix[i][k])
				{
					count--;
					stop = 1;
					break;
				}
				else if (j == ROWS - 1) stop = 1;
			}
			
		}
	}
	cout << "Count rows with unique items: " << count << endl;
	
}

