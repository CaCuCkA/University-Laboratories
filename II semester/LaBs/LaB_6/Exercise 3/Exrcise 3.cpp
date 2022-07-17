#include <iostream>
#include <string>
#include <sstream>
#include "stack.h"

using namespace std;

int main()
{
	Stack numbers;
	string example;
	


	cout << "Enter Prefix Polish inscription: " << endl;
	getline(cin, example);
	istringstream ss(example);
	int findInt;
	char temp[10];
	char sign;
	while (!ss.eof())
	{
		while (ss >> findInt) { numbers.push(findInt); }

		if (!ss.eof())
		{
			ss.clear();
			ss.unget();
			ss >> sign;

			if (numbers.getSize() < 2)
			{
				cerr << "Error! Not enough values!" << endl;
				return 0;
			}

			int right = numbers.top();
			numbers.pop();

			
			int left = numbers.top();
			numbers.pop();

			switch (sign)
			{
			case '+': numbers.push(left + right); break;
			case '-': numbers.push(left - right); break;
			case '*': numbers.push(left * right); break;
			case '/': numbers.push(left / right); break;
			default: 
				cerr << "Error! Unsupported sign." << endl;
				return 0;
				break;
			}
		}
		if (ss.eof() && numbers.getSize() > 1)
		{
			if (numbers.getSize() != 2)
			{
				cerr << "Error! We can calculate your result!" << endl;
				return 0;
			}
			ss.clear();
			ss.unget();
			ss >> sign;

			int right = numbers.top();
			numbers.pop();

			
			int left = numbers.top();
			numbers.pop();

			switch (sign)
			{
			case '+': numbers.push(left + right); break;
			case '-': numbers.push(left - right); break;
			case '*': numbers.push(left * right); break;
			case '/': numbers.push(left / right); break;
			default:
				cerr << "Error! Unsupported sign." << endl;
				return 0;
				break;
			}
		}
	}
	if (numbers.getSize() != 1)
	{
		cerr << "Error! You haven`t got a result" << endl;
		return 0;
	}

	cout << "Your result: " << numbers.top() << endl;
	return 0;
}