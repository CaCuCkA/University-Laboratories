#include <iostream>
#include <vector>

using namespace std;

void displayVector(vector<int>);

int main()
{
	int size;
	int i = 0, k = 0, j = 0;

	vector<int> A = { 11, 22, 33, 54 };
	vector<int> B = { -3, -2, -1, 0, 99};

	size = A.size() + B.size();

	vector<int> C(size);

	while (j < B.size() && i < A.size())
	{
		if (A[i] < B[j])
		{
			C[k] = A[i];
			i++;
		}

		else
		{
			C[k] = B[j];
			++j;
		}

		k++;
	}

	
	for (; i < A.size(); i++, k++)
		C[k] = A[i];
	for (; j < B.size(); j++, k++)
		C[k] = B[j];


	cout << "First vector: " << endl;
	displayVector(A);

	cout << "Second vector: " << endl;
	displayVector(B);

	cout << "Third vector: " << endl;
	displayVector(C);

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

