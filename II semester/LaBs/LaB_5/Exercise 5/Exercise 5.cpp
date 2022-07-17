#include <iostream>
#include <vector>


std::vector<std::vector<int>>autoInitializeMatrix(std::vector<std::vector<int>>&, int);
void findSum(std::vector<std::vector<int>>&, int, int);
void displayMatrix(std::vector<std::vector<int>>&);
void findProduct(std::vector< std::vector<int>>&, int, int);

int main()
{
	using namespace std;

	int rows, cols;
	vector<vector<int>> matrix;

	cout << "Input rows: " << endl;
	cin >> rows;

	matrix.resize(rows);

	cout << "Input cols (cols >= rows): " << endl;
	cin >> cols;

	cout << "=====================================================================" << endl;
	cout << "Matrix is done" << endl;
	autoInitializeMatrix(matrix, cols);

	cout << "=====================================================================" << endl;
	
	for (int i = 0; i < cols; i++)
	{ 
		findSum(matrix, 0, i);
		cout << "------------------------------------------- " << endl;

	}
	for (int j = 1; j < rows; j++)
	{ 
		findSum(matrix, j, 0);
		cout << "------------------------------------------- " << endl;
	}

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
	return 0;
}


std::vector<std::vector<int>>initializeMatrix(std::vector<std::vector<int>>& vec, int cols)
{
	using namespace std;
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

std::vector<std::vector<int>>autoInitializeMatrix(std::vector<std::vector<int>>& vec, int size)
{
	using namespace std;
	srand(time(0));

	for (int i = 0; i < vec.size(); i++) { vec[i].resize(size); }

	for (int i = 0; i < vec.size(); i++)
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

void displayMatrix(std::vector<std::vector<int>>& vec)
{
	using namespace std;
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

void findSum(std::vector<std::vector<int>>& vec, int R, int C)
{
	using namespace std;
	int sum = 0;
	
	if (!R && !C)
	{
		cout << "Main diagonal: { ";

		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i][i] << " ";
			sum += vec[i][i];
		}
	}

	if (R)
	{
		cout << "Parallel diagonal: { ";
		for (int i = 0; i < vec.size()- R; i++)
		{
			cout << vec[i + R][i] << " ";
			sum += vec[i + R][i];
		}
	}

	if(C)
	{		
		cout << "Parallel diagonal: { ";

		for (int i = 0; i < vec[0].size() - C; i++)
		{
			cout << vec[i][i + C] << " ";
			sum += vec[i][i + C];
		}
		
	}

	cout << "} sum = " << sum << endl;
}

void findProduct(std::vector<std::vector<int>>& vec, int R, int C)
{
	using namespace std;
	int product = 1;
		
	if (!R && !C)
	{
		cout << "Side diagonal elements: {";
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i][vec[0].size() - (i + 1)] << " ";
			product *= vec[i][vec[0].size() - (i + 1)];
		}
	}

	if (C)
	{
		cout << "Parallel diagonal: { ";

		for (int i = 0; i < vec[0].size() - C; i++)
		{
			cout << vec[i][vec[0].size() - (i + C + 1)] << " ";
			product *= vec[i][vec[0].size() - (i + C + 1)];
		}
			
			
	}
	if(R)
	{
		cout << "Parallel diagonal: { ";
		for (int i = 0; i < vec.size() - R; i++)
		{
			cout << vec[i + R][vec[0].size() - i - 1] << " ";
			product *= vec[i + R][vec[0].size() - i - 1];
		}
	}
	


	cout << "} product = " << product << endl;
}
