#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

void main()
{
	string path = "valuesEx4extra.txt";

	ifstream fin;

	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error! File can`t be open." << endl;
	}
	else
	{
		int count = 0;
		char getString[20];

		int fiV, seV, thiV;
		
		while (!fin.eof())
		{
			fin.getline(getString, 20);
			stringstream iss(getString);

			int waste = 1;
			iss >> fiV >> seV >> thiV;
			while (!iss.eof())
			{
				if ((fiV < seV && thiV < seV) || (seV < fiV && seV < thiV))
				{
					fiV = seV;
					seV = thiV;
					iss >> thiV;
					if (!((fiV < seV && thiV < seV) || (seV < fiV && seV < thiV))) waste = 0;
					cout << setw(4) << fiV << setw(4) <<  seV << setw(4) << thiV;
				}
				else
				{
					waste = 0;
					while (!iss.eof()) iss >> setw(4) >> thiV;
				}
			}
			cout << endl;
			if (waste) ++count;
		}
		cout << "Count: " << count << endl;

		fin.close();
	}
}