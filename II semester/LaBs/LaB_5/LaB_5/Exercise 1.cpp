#include <iostream>
#include <vector>
#include <cstdlib>
#include<ctime>

using namespace std;

vector<vector<int>>initializeMatrix(vector<vector<int>>&, int);
vector<vector<int>>autoInitializeMatrix(vector<vector<int>>&, int);
void displayMatrix(vector<vector<int>>&);

int main()
{
	int rows, cols;
	vector<vector<int>> matrix;

	int maxValue = 0, id = 0;

	cout << "Input rows: " << endl;
	cin >> rows;

	matrix.resize(rows);

	cout << "Input cols: " << endl;
	cin >> cols;

	
	//initializeMatrix(matrix, cols);

	autoInitializeMatrix(matrix, cols);

	cout << "Matrix is done" << endl;
	displayMatrix(matrix);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] > maxValue)
			{
				id = i;
				maxValue = matrix[i][j];
			}		
		}
	}

	matrix.erase(matrix.begin() + id);
	rows--;
	maxValue = 0;

	cout << "Matrix after deleting row:" << endl;
	displayMatrix(matrix);
	cout << maxValue << endl;
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matrix[i][j] > maxValue)
			{
				id = j;
				maxValue = matrix[i][j];
			}
		}
	}

	for (int i = 0; i < matrix.size(); i++)
		matrix[i].erase(matrix[i].begin() + id);

	cout << "Matrix after deleting col:" << endl;
	displayMatrix(matrix);

	return 0;
}

vector<vector<int>>autoInitializeMatrix(vector<vector<int>>& vec, int cols)
{
	srand(time(0));

	for (int i = 0; i < vec.size(); i++) { vec[i].resize(cols); }

	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < cols; j++)
		{
			int element = 1 + rand() % (9 + 1);
			vec[i][j] = element;
			cout << element << '\t';
		}
		cout << endl;
	}
	cout << endl << endl;

	return vec;
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