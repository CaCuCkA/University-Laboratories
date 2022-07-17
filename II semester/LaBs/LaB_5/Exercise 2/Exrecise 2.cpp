#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>initializeMatrix(vector<vector<int>>&, int);
void displayMatrix(vector<vector<int>>&);

int main()
{
	int rows, cols;
	vector<vector<int>> matrix;
	

	cout << "Input rows: " << endl;
	cin >> rows;

	matrix.resize(rows);

	cout << "Input cols: " << endl;
	cin >> cols;

	vector<int> zeroRow(cols);
	for (int i = 0; i < zeroRow.size(); i++) { zeroRow[i] = 0; }

	vector<int> rowIds;
	vector<int> colIds;

	initializeMatrix(matrix, cols);

	cout << "Matrix is done" << endl;
	displayMatrix(matrix);


	for (int i = 0; i < matrix.size(); i++)
	{
		int addZero = 1;

		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (matrix[i][j] < 0)
				addZero = 0;
		}

		if (addZero)
			rowIds.push_back(i);
	}

	for (int j = 0; j < cols; j++)
	{
		int addOne = 1;

		for (int i = 0; i + 1 < rows; i++)
		{
			if (matrix[i][j] <= matrix[i + 1][j])
				addOne = 0;
		}

		if (addOne)
			colIds.push_back(j);
	}


	for (int i = rowIds.size() - 1; i >= 0; i--)
	{
		matrix.insert(matrix.begin() + rowIds[i] + 1, zeroRow);
	}

	cout << "Matrix after adding zero rows: " << endl;
	displayMatrix(matrix);

	for (int i = colIds.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < matrix.size(); j++)
			matrix[j].insert(matrix[j].begin() + colIds[i], 1);
	}

	cout << "Matrix after adding 'one' cols: " << endl;
	displayMatrix(matrix);






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