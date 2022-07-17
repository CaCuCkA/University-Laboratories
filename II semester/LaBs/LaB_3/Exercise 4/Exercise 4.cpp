#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void main()
{
	string path = "valuesEx4.txt";

	ifstream fin;

	fin.open(path);

	if (!fin.is_open())
	{
		cout << "Error! File can`t be open." << endl;
	}
	else
	{
		int count = 0;
		int waste = 1;
	
		int K;
		fin >> K;
		//cout << K << endl;

		int fiV, seV, thiV;
	
		for (int i = 0; i < K; i++)
		{
			fin >> fiV >> seV >> thiV;
			waste = 1;

			while (thiV != 0)
			{
				//cout << fiV << '\t' << seV << '\t' << thiV << '\t';
				if ((fiV < seV && thiV < seV) || (seV < fiV && seV < thiV))
				{
					fiV = seV;
					seV = thiV;
					fin >> thiV;
					cout << fiV << '\t' << seV << '\t' << thiV << '\t';
				}
				else
				{
					waste = 0;
					while (thiV != 0) fin >> thiV;
					//cout << thiV << endl;
				}
			}
			cout << endl;
			if (waste) count++;
		}
		cout << "Count: " << count << endl;
					
		fin.close();
	}
}