#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string path = "valuesEx3.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error! File can`t be open. Try again" << endl;
		return -1;
	}
	else
	{
		int count = 0;
		int rows, cols;
		fin >> rows >> cols;

		int** array = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			array[i] = new int[cols];
		}
/////////////////////////////////////////////////
		cout << "Array is ready: " << endl;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				fin >> array[i][j];
				cout << array[i][j] << '\t';
			}
			cout << endl;
		}
/////////////////////////////////////////////////
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (array[i][j] == 2)
				{
					count++;
					break;
				}
			}
		}
		cout << "Count: " << count << endl;
/////////////////////////////////////////////////

		for (int i = 0; i < rows; i++)
		{
			delete[] array[i];
		}
		delete[] array;
		fin.close();
	}

/////////////////////////////////////////////////
	
	return 0;

}