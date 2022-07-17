#include <iostream>
#include <vector>
#include <iterator>
#define MIN_VALUE 0.000000001

using namespace std;

int main()
{
	int count = 0;
	int temp_count = 0;
	double a1, a2, diff = 0, temp_diff = 0;


	vector<double> FloatVector = { 1.1, 2.2, 3.3};

	vector<double>::iterator it = FloatVector.begin();
	while (it + 1 != FloatVector.end())
	{
		a1 = *it;
		
		advance(it, 1);

		a2 = *it;

		temp_diff = a2 - a1;

		double gl_diff = temp_diff - diff;

		if (gl_diff  < MIN_VALUE && -MIN_VALUE < gl_diff)
		{
			temp_count++;
			//cout << temp_count << endl;
		}


		if ((gl_diff > MIN_VALUE || it + 1 == FloatVector.end()) &&  temp_count > 0)
		{
			count++;
			temp_count = 0;
		}

		diff = temp_diff;

	}

	cout << "Array length: " << FloatVector.size() << endl;
	cout << "Amount of lands: " << count << endl;
	return 0;
}