#include <iostream>
#include <vector>
#define MAX 10000000000000

using namespace std;

vector<vector<int>>initializeMatrix(vector<vector<int>>&, int);
void displayMatrix(vector<vector<int>>&);

int main()
{
	int rows, cols;
	vector<vector<int>> matrix;

	int pair = 0, 
		unpair = 0;

	int pairId = 0, unpairId = 0;

	int maxColValue = 0,
		minColValue = MAX;

	int maxId = 0,
		minId = 0;


	cout << "Input rows: " << endl;
	cin >> rows;

	matrix.resize(rows);

	cout << "Input cols: " << endl;
	cin >> cols;

	initializeMatrix(matrix, cols);

	cout << "=====================================================================" << endl;
	cout << "Matrix is done" << endl;
	displayMatrix(matrix);

	for (int i = 0; i < matrix.size(); i++)
	{
		int pair = 1,
			unpairId = 1;

		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j]%2)
				pair = 0;
			else
				unpair = 0;
		}

		if (pair)
			pairId = i;

		if (unpair)
			unpairId = i;
	}
	
	cout << "=====================================================================" << endl;

	cout << "Row with all unpair numbers: ";
	for (int i = 0; i < cols; i++) { cout << matrix[unpairId][i] << '\t'; }

	cout << "\nRow with all pair numbers: ";
	for (int i = 0; i < cols; i++) { cout << matrix[pairId][i] << '\t'; }

	matrix[pairId].swap(matrix[unpairId]);

	cout << "\nMatrix after swaping cols with min and max values: " << endl;
	displayMatrix(matrix);


	for (int j = 0; j < cols; j++)
	{
		for (int i = 0; i < rows; i++)
		{
			if (matrix[i][j] > maxColValue)
			{
				maxColValue = matrix[i][j];
				maxId = j;

			}
				

			if (matrix[i][j] < minColValue)
			{
				minColValue = matrix[i][j];
				minId = j;
			}
				
		}
	}

	cout << "=====================================================================" << endl;

	cout << "The max value is " << maxColValue << " in " << maxId + 1 << "th coll" << endl;
	cout << "The min value is " << minColValue << " in " << minId + 1 << "th coll" << endl;

	for (int i = 0; i < matrix.size(); i++)
		swap(matrix[i][minId], matrix[i][maxId]);

	cout << "Matrix after swaping cols with min and max values: " << endl;
	displayMatrix(matrix);
	return 0;

}


vector<vector<int>>initializeMatrix(vector<vector<int>>& vec, int cols)
{

	for (int i = 0; i < vec.size(); i++) { vec[i].resize(cols); }


	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << "Enter " << j + 1 << "th element: " << endl;
			cin >> vec[i][j];
		}
	}

	return vec;
}


void displayMatrix(vector<vector<int>>& vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			cout << vec[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl << endl;
}

