#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int>);
void reverseDisplayVector(vector<int>);

int main()
{
	int K;
	int element;
	
	
	cout << "Enter amount of elements: ";
	cin >> K;
	vector<int> firstVector(K);



	for (int i = 0; i < firstVector.size(); i++)
	{
		cout << "Enter " << i + 1 << "th element: ";
		cin >> firstVector[i];

	}
	cout << endl << "Massive is full!" << endl;

	vector<int> secondVector;

	for (int i = 0; i < K; i++)
	{
		if (!(firstVector[i]%2))
			secondVector.push_back(firstVector[i]);
	}
	
	cout << endl << "First vector: " << endl;
	displayVector(firstVector);

	cout << "Second modified vector: " << endl;
	reverseDisplayVector(secondVector);

	return 0;
}


void reverseDisplayVector(vector<int> vec)
{
	int stop = 0;
	for (unsigned int i = vec.size() - 1;  !stop ; i--)
	{
		
		if (!(i % 4))
			cout << endl;
		cout << vec[i] << '\t';
		if (i == 0) stop = 1;
	}
	cout << endl << endl;
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
