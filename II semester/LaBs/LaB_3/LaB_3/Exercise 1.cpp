#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	string path = "valuesEx1.txt";

	double product = 1;
	double *pProduct = &product;

	ifstream fin;
	fin.open(path);

	char ch;
	if (!fin.is_open())
	{
		cout << "Error! File can`t be open. Try again" << endl;
	}
	else
	{
		cout << "File is open!" << endl;
		int size;
		fin >> size;
		double* array = new double[size];
		//cout << size;

		for (int i = 0; i < size; i++)
		{
			double value;
			fin >> value;
			if (fin.fail())
			{
				cerr << "Number have unfitted type" << endl;
				fin.clear();
				fin.ignore(32767, '\t');
				continue;
			}
			else
			{
				array[i] = value;
				value = array[i] - floor(array[i]);
				cout << value << endl;
				*pProduct *= value;
			}
			
			//cout << array[i] << endl;
		}
		cout << fixed << product << endl;


		delete[] array;

		fin.close();
		cout << "File is closed!" << endl;
	}

	
}
