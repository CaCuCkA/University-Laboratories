#include <iostream>
#include <vector>


int main()
{
	using namespace std;

	int rows, cols;
	vector<vector<int>> matrix;
	srand(time(0));

	cout << "Input rows: " << endl;
	cin >> rows;

	matrix.resize(rows);

	cout << "Input cols (cols >= rows): " << endl;
	cin >> cols;

	cout << "=====================================================================" << endl;
	cout << "Matrix is done" << endl;
	
	

	for (int i = 0; i < matrix.size(); i++) { matrix[i].resize(cols); }

	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < cols; j++)
		{
			matrix[i][j] = 1 + rand() % (9 + 1);
			cout << matrix[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl << endl;

	cout << "=====================================================================" << endl;

	for (int i = 0; i < cols; i++)
	{
		findProduct(matrix, 0, i);
		cout << "------------------------------------------- " << endl;

	}
	for (int j = 1; j < rows; j++)
	{
		findProduct(matrix, j, 0);
		cout << "------------------------------------------- " << endl;
	}

	cout << "=====================================================================" << endl;

	for (int i = 0; i < cols; i++)
	{
		findPair(matrix, 0, i);
		cout << "------------------------------------------- " << endl;

	}
	for (int j = 1; j < rows; j++)
	{
		findPair(matrix, j, 0);
		cout << "------------------------------------------- " << endl;
	}
	return 0;
}

void findProduct(std::vector<std::vector<int>>& vec, int R, int C)
{
	using namespace std;
	int sum = 1;

	if (!R && !C)
	{
		cout << "Main diagonal: { ";

		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i][i] << " ";
			sum *= vec[i][i];
		}
	}

	if (R)
	{
		cout << "Parallel diagonal: { ";
		for (int i = 0; i < vec.size() - R; i++)
		{
			cout << vec[i + R][i] << " ";
			sum *= vec[i + R][i];
		}
	}

	if (C)
	{
		cout << "Parallel diagonal: { ";

		for (int i = 0; i < vec[0].size() - C; i++)
		{
			cout << vec[i][i + C] << " ";
			sum *= vec[i][i + C];
		}

	}

	cout << "} sum = " << sum << endl;
}

void findPair(std::vector<std::vector<int>>& vec, int R, int C)
{
	using namespace std;
	int evenNumbers = 0;

	if (!R && !C)
	{

		cout << "Side diagonal elements: {";
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i][vec[0].size() - (i + 1)] << " ";
			if (!(vec[i][vec[0].size() - (i + 1)] % 2))
				evenNumbers++;
		}
	}

	if (C)
	{
		cout << "Parallel diagonal: { ";

		for (int i = 0; i < vec[0].size() - C; i++)
		{
			cout << vec[i][vec[0].size() - (i + C + 1)] << " ";
			if (!(vec[i][vec[0].size() - (i + C + 1)] % 2))
				evenNumbers++;
			
		}


	}
	if (R)
	{
		cout << "Parallel diagonal: { ";
		for (int i = 0; i < vec.size() - R; i++)
		{
			cout << vec[i + R][vec[0].size() - i - 1] << " ";
			if (!(vec[i + R][vec[0].size() - i - 1] % 2))
				evenNumbers++;

		}
	}



	cout << "} amount of even numbers  = " << evenNumbers << endl;
}

