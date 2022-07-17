#include <iostream>
#include <vector>

using namespace std;


vector<vector<int>>autoInitializeMatrix(vector<vector<int>>&, int);
void displayMatrix(vector<vector<int>>&);

int main()
{
	int size;
	vector<vector<int>> matrix;

	cout << "Enter size for a square matrix: " << endl;
	cin >> size;

	matrix.resize(size);

	cout << "=====================================================================" << endl;
	cout << "Matrix is done" << endl;
	autoInitializeMatrix(matrix, size);

	cout << "=====================================================================" << endl;
	cout << "Main diagonal elements: {";
	for (int i = 0; i < size; i++) { cout << matrix[i][i] << '\t'; }
	cout << "}" << endl;

	cout << "Side diagonal elements: {";
	for (int i = 0; i < size; i++) { cout << matrix[i][size - (i + 1)] << '\t'; }
	cout << "}" << endl;
	cout << "=====================================================================" << endl;

	cout << "Matrix after changes: " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (i <= j && i <= size - (j + 1))
			{
				matrix[i][j] = 0;
			}
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	return 0;
}


vector<vector<int>>initializeMatrix(vector<vector<int>>& vec, int cols)
{

	for (int i = 0; i < vec.size(); i++) { vec[i].resize(cols); }


	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < cols; j++)
		{
			//cout << "Enter " << j + 1 << "th element: " << endl;
			//cin >> vec[i][j];
			vec[i][j] = 1;
		}
	}

	return vec;
}

vector<vector<int>>autoInitializeMatrix(vector<vector<int>>& vec, int size)
{
	srand(time(0));

	for (int i = 0; i < size; i++) { vec[i].resize(size); }

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			vec[i][j] = 1 + rand() % (9 + 1);
			cout << vec[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl << endl;

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

