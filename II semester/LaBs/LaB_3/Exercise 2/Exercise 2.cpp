#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main()
{
	string path = "valuesEx2.txt";
	ifstream fin;
	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error! File can`t be open. Try again" << endl;
		return -1;
	}
	else
	{
		cout << "File is open!" << endl;

		int i = 0, temp_i = 0;
		int temp_value, value;

		int K;
		fin >> K;

		while (!fin.eof())
		{
			fin >> temp_value;
			temp_i++;
			if (temp_value > K)
			{
				i = temp_i;
				value = temp_value;
			}
		}
		if (i != 0) cout << "Lat number that is bigger than " << K << " is " << value << " with id = " << i << endl;
		else cout << 0 << endl;
		fin.close();
		cout << "File is closed!" << endl;
	}
	return 0;
}