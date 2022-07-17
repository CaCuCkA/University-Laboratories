#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
#include <stack>
#define MIN_VALUE 0.000000001

void displayVector(std::vector<double> vec);
void switchElements(std::vector<double>, std::queue<double>, int, int, int, int, int, int);
void defineValues(std::queue<int>, int&, int&, int&, int&, int&, int&);
int countArithLength(std::vector<double>::iterator&, std::vector<double>&, std::queue<double>&, std::queue<int>&);

int main()
{
	double temp = 0;
	int count = 0;

	int minFirstId = 0, minLastId = 0, minValue = 10000;
	int maxFirstId = 0, maxLastId = 0, maxValue = 0;


	std::queue<double> q;
	std::stack<double> st;
	std::queue<int> q2;

	std::vector<double> FloatVector = { 4.5, 7.6, 8.8, 1.1, 2.2, 3.3, 5.7, 5.9, 6.1, 6.3, 6.5, 6.7, 6.9, 7.3, 7.6, 7.9, 8.2, 8.5, 8.9 };

	std::vector<double>::iterator it = FloatVector.begin();
	
	// Counting arithmetical lands 
	count = countArithLength(it, FloatVector, q, q2);
	
	std::cout << "Vector before deleting: " << std::endl;
	displayVector(FloatVector);


	std::cout << "Vector`s length before deleting borders: " << FloatVector.size() << std::endl;
	std::cout << "Amount of lands before deleting borders: " << count << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	
	// deleting right and left borders 

	std::cout << "Borders those should be deleted : " << std::endl;

	for (int i = 0; !q.empty(); i++)
	{
		temp = q.front();
		

		if (temp == FloatVector[i])
		{	
			std::cout << temp << std::endl;
			FloatVector.erase(FloatVector.begin() + i);
			--i;
			q.pop();
			
		}

	}
	std::cout << "------------------------------------------------------" << std::endl;


	std::cout << "Vector after deleting deleting borders: " << std::endl;
	displayVector(FloatVector);

	it = FloatVector.begin();
	std::cout << "Array length after deleting borders: " << FloatVector.size() << std::endl;
	std::cout << "Amount of lands after deleting borders: " << countArithLength(it, FloatVector, q, q2) << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;

	//Filling-up queue	
	std::cout << maxFirstId << " " << minFirstId << std::endl;

	//Define borders of long and short lands and their length
	defineValues(q2, maxFirstId, maxLastId, maxValue, minFirstId, minLastId, minValue);
	
	//Changing sequence
	if (minFirstId > maxFirstId)
		switchElements(FloatVector, q, minFirstId, minLastId, minValue, maxFirstId, maxLastId, maxValue);
	
		
	if (maxFirstId > minFirstId)
		switchElements(FloatVector, q, maxFirstId, maxLastId, maxValue, minFirstId, minLastId, minValue);
		

	displayVector(FloatVector);


	it = FloatVector.begin();
	std::cout << "Array length after all changes: " << FloatVector.size() << std::endl;
	std::cout << "Amount of lands after all changes: " << countArithLength(it, FloatVector, q, q2) << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
	
	return 0;
}


//Displaying function

void displayVector(std::vector<double> vec)
{
	for (unsigned int i = 0; i < vec.size(); i++)
	{
		if (!(i % 4))
			std::cout << std::endl;
		std::cout << vec[i] << '\t';
	}
	std::cout << std::endl << std::endl;
}


//Switching two arithmetical progressions

void switchElements(std::vector<double> vec, std::queue<double> que, int farFirstId,
	int farLastId, int farValue, int nearFirstId, int nearLastId, int nearValue )
{
	for (int i = nearFirstId; i < nearLastId + 1; i++)
	{
		que.push(vec[i]);
	}

	int temp = nearLastId;

	while (!que.empty())
	{
		vec.insert(vec.begin() + temp + 1, que.front());
		temp++;
		que.pop();
	}

	while (farValue)
	{
		que.push(vec[farFirstId]);
		vec.erase(vec.begin() + farFirstId);
		farValue--;
	}

	temp = nearLastId;

	while (!que.empty())
	{
		vec.insert(vec.begin() + temp + 1, que.front());
		temp++;
		que.pop();
	}

	while (nearValue)
	{
		vec.erase(vec.begin() + nearFirstId);
		nearValue--;
	}

}


//Define max`s and min`s length weight first id and second id.

void defineValues(std::queue<int> que, int& maxFid, int& maxSid, int& maxVal,
	int& minFid, int& minSid, int& minVal)
{
	while (!que.empty())
	{
		int elOne = que.front();
		que.pop();
		int elTwo= que.front();
		que.pop();

		int temp = elTwo - elOne;

		if (temp < minVal)
		{
			minVal = temp;
			minFid = elOne;
			minSid = elTwo;
		}
			

		if (temp > maxVal)
		{
			maxVal = temp;
			maxFid = elOne;
			maxSid = elTwo;
		}
	}
}


//Count length

int countArithLength(std::vector<double>::iterator &it, std::vector<double> &vec, std::queue<double> &que,
	std::queue<int>& que2)
{
	double a1 = 0, a2 = 0;
	double diff = 0;
	int land_size1 = 0, land_size2 = 0;
	int count = 0, temp_count = 0;

	while (it + 1 != vec.end())
	{
		a1 = *it;
		land_size1++;

		advance(it, 1);

		a2 = *it;

		double temp_diff = a2 - a1;

		double gl_diff = temp_diff - diff;

		if (gl_diff < MIN_VALUE && -MIN_VALUE < gl_diff)
		{
			temp_count++;
			land_size2++;
		}

		if ((gl_diff > MIN_VALUE || it + 1 == vec.end()) && temp_count > 0)
		{
			count++;
			temp_count = 0;

			que.push(vec[land_size1 - land_size2 - 2]);
			que2.push(land_size1 - land_size2 - 2);
			que.push(vec[land_size1 - 1]);
			que2.push(land_size1 - 1);

			land_size2 = 0;

		}


		diff = temp_diff;

	}
	return count;
}