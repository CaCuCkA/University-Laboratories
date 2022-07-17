#include <iostream>
#include <vector>
#include <iterator>
#include <stack>

using namespace std;

void displayVector(vector<int> vec);

int main()
{
	int temp;
	vector<int> intVector = { -1, -1, -2, -3, -3};

	cout << "Vector`s length: " << intVector.size() << endl;
	cout << "Vector`s capacity: " << intVector.capacity() << endl;
	cout << "Vector max_size() before modifications: " << intVector.max_size() << endl;
	cout << "-------------------------------------------------" << endl;
	
/*
	for (int i = 0; i + 1 < intVector.size(); i++)
	{
		if (intVector[i + 1] > intVector[i])
		{
			temp = intVector[i];
			intVector[i] = intVector[i + 1];
			intVector[i + 1] = temp;
		}
	}
*/
	//displayVector(intVector);

	for (int i = 0; i < intVector.size() - 1; i++)
	{
		if (intVector[i] == intVector[i + 1])
		{
			intVector.erase(intVector.begin() + i);
		}
			
	}

	displayVector(intVector);
	cout << "-------------------------------------------------" << endl;
	cout << "Vector`s length after deleting same elements: " << intVector.size() << endl;
	cout << "Vector`s capacity after deleting same elements: " << intVector.capacity() << endl;
	cout << "Vector`s max_size() after deleting same elements: " << intVector.max_size() << endl;
	cout << "-------------------------------------------------" << endl;

	for (int i = 0; i < intVector.size(); i++)
	{
		if (intVector[i] < 0)
		{
			intVector.insert(intVector.begin() + i + 1, 0);
			++i;
		}
			
	}
	
	displayVector(intVector);

	cout << "-------------------------------------------------" << endl;
	cout << "Vector`s length after adding zeros after negative elements: " << intVector.size() << endl;
	cout << "Vector`s capacity after adding zeros after negative elements: " << intVector.capacity() << endl;
	cout << "Vector`s max_size() after adding zeros after negative elements: " << intVector.max_size() << endl;
	cout << "-------------------------------------------------" << endl;

	return 0;
}



void displayVector(vector<int> vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (!(i % 4))
			cout << endl;
		cout << vec[i] << '\t';
	}
	cout << endl << endl;
}