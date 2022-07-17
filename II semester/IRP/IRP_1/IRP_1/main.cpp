#include <iostream>
#include <conio.h>
#include <cstring>
#include <sstream>
#include <stdio.h>
#include <string>
#include <fstream>
#define BUFFLEN 256
#define MAX 100
#define MIN 10
#define ROWS 5

using namespace std;


//Task 1
void taskOneC()
{
	char str1[MAX];
	char str2[MIN] = " are";

	puts("Enter a string: ");
	fgets(str1, MAX, stdin);

	char* p = strstr(str1, str2);

	if (p)
	{
		strcpy(p,  strlen(str2) + p);
		printf(str1);
	}
	else
	{
		printf("String doesn`t consist 'are' \n");
	}
}

void taskOneCPP()
{
	string str1;
	string str2 = "are";

	cout << "Enter string: ";
	getline(cin, str1);

	int location = str1.find(str2);
	int size = str2.length();

	if (location != std::string::npos)
	{
		str1.erase(location, size);
		cout << "Your str: " << endl << str1;
	}

	else
		cout << "String doesn`t consist 'are'" << endl;

	
}


//Task 2
void taskTwoC()
{
	char letter = 'a';
	char str1[20];
	char str2[MIN] = "bc";
	char temp[MAX] = "\0";

	puts("Enter a string: ");
	fgets(str1, 20, stdin);
	
	if ((strlen(str1) + strlen(str2) < 19))
	{
		

		if (strchr(str1, letter))
		{
			char* p = strchr(str1, letter) + 1;
			strcpy(temp, p);
			strcpy(p, str2);
			p += strlen(str2);
			strcpy(p, temp);
			printf(str1);
		}

		else 
			printf("Sorry your string doesn`t consist letter 'a'\n");
		
	}
	
	else
		printf("Sorry your string is full. we can add substring\n");
	

}

void taskTwoCPP()
{
	string str1;
	string str2 = "bc";
	char letter = 'a';

	cout << "Enter string: ";
	getline(cin, str1);

	
	int location = str1.find(letter) + 1;

	if (location)
	{
		str1.insert(location, str2);
		cout << "Your str: " << endl << str1;
	}

	else
		cout << "Sorry your string doesn`t consist letter 'a'" << endl;
	
	
}


//Task 3
void taskThreeC()
{
	char S[MAX];
	char X[7] = "\0";
	char letter = 'a';

	puts("Enter a string S: ");
	fgets(S, MAX, stdin);

	if (strchr(S, letter))
	{
		char* p = strchr(S, letter) + 1;
		strncat(X, p, 6);
		printf(X);
	}

	else
		printf("Sorry your string doesn`t consist letter 'a'\n");
	

}

void taskThreeCPP()
{
	string S;
	string X;
	char letter = 'a';

	cout << "Enter string: ";
	getline(cin, S);

	int location = S.find(letter) + 1;
	if (location)
	{
		X.append(S, location, 6);
		cout << "Your str: " << endl << X;
	}

	else
		cout << "Sorry your string doesn`t consist letter 'a'" << endl;
	
	

}


//Task 4
void taskFourC()
{
	
	char str1[MAX];
	char str2[MIN] = "***";

	puts("Enter a string: ");
	fgets(str1, MAX, stdin);

	while (true)
	{
		char* p = strstr(str1, str2);

		if (p)
		{
			strcpy(p, strlen(str2) + p);
			printf(str1);
		}
		else
		{
			printf("String doesn`t consist '***' \n");
			printf(str1);
			break;
		}
	}
	
}

void taskFourCPP()
{
	int n = 0;
	string str1;
	string str2 = "***";

	cout << "Enter string: ";
	getline(cin, str1);

	while (str1.find(str2) < MAX)
	{
		int location = str1.find(str2);

		if (location)
		{
			int size = str2.length();
			str1.erase(location, size);
			n = 1;
		}
		else
		{
			cout << "All '***' were deleted" << endl;
			break;
		}
		
	}
	if(n)
		cout << "Your str: " << endl << str1;

	else
		cout << "Sorry your string doesn`t consist '***'" << endl;
}


//Task 5
void taskFiveC()
{
	FILE* filePointer = NULL;
	char name[] = "sentences.txt";
	char buffer[256];
	char *strArray[ROWS];
	int number = 0;
	int iMax = 0; float fMax = 0;
	int k = 0, j = 0, l = 0;
	char* intArr[MIN];
	char* floatArr[MIN];
	char* strPointer;
	int intArray[MIN]; float floatArray[MIN];
	int count;

	filePointer = fopen(name, "r");


	for (int i = 0; i < MIN; i++)
	{
		intArray[i] = NULL;
		floatArray[i] = NULL;
	}

	if (!filePointer)
	{
		perror("File cannot be open. Try again!");
	}

	else
	{
		for (count = 0; !feof(filePointer); count++)
		{
			fgets(buffer, 256, filePointer);
			strArray[count] = (char*)malloc(sizeof(char) * BUFFLEN);
			memcpy(strArray[count], buffer, 256);
			//cout << strArray[i] << endl;
		}
	}
	fclose(filePointer);
	
	for (int i = 0; i < count; i++)
	{
		strPointer = strdup(strArray[i]);
		char* token = strdup(strArray[i]);
		token = strtok(token, " ");
		

		while (token != NULL)
		{
			if (isdigit(*token))
			{
				
				for (int i = 0; i < strlen(token); i++)
				{
					if (token[i] == '.')
						number = 1;
				}
				if (number)
				{
					if (fMax < atof(token))
						fMax = atof(token);
					
					number = 0;
				}
				else
				{
					if (iMax < atoi(token))
						iMax = atoi(token);
				}
			}
			token = strtok(NULL, " ");
		}

		if (iMax)
		{
			intArray[k] = iMax;
			intArr[k] = strPointer;
			k++;
			iMax = 0;
		}
		

		if (fMax)
		{
			floatArray[j] = fMax;
			floatArr[j] = strPointer;
			j++;
			fMax = 0;
		}

		
	}

	if (k)
	{
		printf("Sorted pointers by integers: \n\n");

		if (k > 1)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int i = 0; intArray[i + 1]; i++)
				{
					if (intArray[i + 1] < intArray[i])
					{
						int iTemp = intArray[i];
						intArray[i] = intArray[i + 1];
						intArray[i + 1] = iTemp;

						char* cTemp = intArr[i];
						intArr[i] = intArr[i + 1];
						intArr[i + 1] = cTemp;
					}
				}
			}
			


			for (int i = 0; intArray[i]; i++)
			{
			
				printf("%d\t", *(intArray + i));
				printf("%p\t",intArr + i);
				printf("%s\n", *(intArr + i));
			}
		}

		else
		{
			printf("%d\t", *intArray);
			printf("%p\t", intArr);
			printf("%s\n", *(intArr));
		}
	}

	else
	{
		printf("String haven`t got any int numbers\n\n");
	}
	
	if (floatArray[0])
	{
		
		printf("\n\nSorted pointers by floats: \n\n");

		if (j > 1)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int i = 0; floatArray[i + 1]; i++)
				{
					
					if (floatArray[i + 1] - floatArray[i] > 0)
					{
						float fTemp = floatArray[i];
						floatArray[i] = floatArray[i + 1];
						floatArray[i + 1] = fTemp;


						char* cTemp = floatArr[i];
						floatArr[i] = floatArr[i + 1];
						floatArr[i + 1] = cTemp;
					}

				}
			}
			

			for (int i = 0; floatArray[i]; i++)
			{
					printf("%g\t", *(floatArray + i));
					printf("%p\t", floatArr + i);
					printf("%s\n", *(floatArr + i));
			}

		}

		else
		{
			printf("%g\t", *floatArray);
			printf("%p\t", floatArr);
			printf("%s\n", *(floatArr));
		}
	}

	else
	{
		printf("\n\nString haven`t got any float numbers\n\n");
	}
	
	free(strPointer);
	for (int i = 0; i < count; i++)
	{
		free(*(strArray + i));
	}

}

void taskFiveCPP()
{
	string path = "sentences.txt";
	ifstream fin;
	fin.open(path);

	string buffer;

	string* ptrIntArray[ROWS];
	string* ptrFloatArray[ROWS];
	string strArray[ROWS];

	float floatMax = 0; int intMax = 0;
	float floatArray[ROWS]; int intArray[ROWS];
	int k = 0, j = 0;


	for (int i = 0; i < ROWS; i++)
	{
		floatArray[i] = 0;
		intArray[i] = 0;
	}

	if (!fin.is_open())
	{
		cout << "Error! File can`t be open. Try again" << endl;
	}

	else
	{
		int i = 0;
		while (!fin.eof())
		{
			getline(fin, buffer);
			strArray[i] = buffer;
			i++;
		}
	}
	fin.close();

	for (int i = 0; i < ROWS; i++)
	{
		intMax = 0; 
		floatMax = 0;
		stringstream ss;
		ss << strArray[i];
		string temp;
		float foundfloat;
		string* strPointer = new string(strArray[i]);
		while (!ss.eof())
		{
			ss >> temp;
			if (stringstream(temp) >> foundfloat)
			{
				if (foundfloat == trunc(foundfloat))
				{
					if (foundfloat > intMax)
						intMax = foundfloat;
					
				}
				else
				{
					if (foundfloat > floatMax)
						floatMax = foundfloat;
				}
			}
		
		}
		if (intMax)
		{
			intArray[k] = intMax;
			ptrIntArray[k] = strPointer;
			k++;
		}

		if (floatMax)
		{
			floatArray[j] = floatMax;
			ptrFloatArray[j] = strPointer;
			j++;
		}
		
	}

	if (k)
	{
		cout << "Ordered string by integers\n\n";

		if (k > 1)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; intArray[i + 1]; i++)
				{
					if (intArray[i] > intArray[i + 1])
					{
						int itemp = intArray[i];
						intArray[i] = intArray[i + 1];
						intArray[i + 1] = itemp;

						string* stemp = ptrIntArray[i];
						ptrIntArray[i] = ptrIntArray[i + 1];
						ptrIntArray[i + 1] = stemp;
					}
				}
			}
			

			for (int i = 0; intArray[i]; i++)
			{
				cout << intArray[i] << '\t' << ptrIntArray[i] << '\t' << *(ptrIntArray[i]) << endl;
			}
		}

		else
		{
			cout << intArray[0] << '\t' << ptrIntArray[0] << '\t' << *(ptrIntArray[0]) << endl;
		}
	}

	else
	{
		cout << "\n\nStrings haven`t got any int numbers" << endl;
	}

	if (j)
	{
		cout << "\n\nOrdered string by floats \n\n";

		if (j > 1)
		{
			for (int j = 0; j < 3; j++)
			{
				for (int i = 0; floatArray[i + 1]; i++)
				{
					if (floatArray[i + 1] > floatArray[i])
					{
						float itemp = floatArray[i];
						floatArray[i] = floatArray[i + 1];
						floatArray[i + 1] = itemp;

						string* stemp = ptrFloatArray[i];
						ptrFloatArray[i] = ptrFloatArray[i + 1];
						ptrFloatArray[i + 1] = stemp;
					}
				}
			}
			

			for (int i = 0; floatArray[i]; i++)
			{
				cout << floatArray[i] << '\t' << ptrFloatArray[i] << '\t' << *(ptrFloatArray[i]) << endl;
			}
		}
		else
		{
			cout << floatArray[0] << '\t' << ptrFloatArray[0] << '\t' << *(ptrFloatArray[0]) << endl;
		}

	
	}

	else
	{
		cout << "\n\nStrings haven`t got any float numbers" << endl;
	}
}



int main()
{
	char c;
	char r;

	while (true)
	{
		system("cls");
		cout << "Input func-number (1-5, ESC for exit)" << endl;
		c = getch();

		switch (c) 
		{
		case '1':
			cout << "Choose C - 0 or C++ - 1 realisation: " << endl;
			r = getch();
			switch (r)
			{
			case '0':
				taskOneC();
				break;
			case '1':
				taskOneCPP();
				break;
			default:
				cout << "You enter incorrect number" << endl;
				break;
			}
			break;

		case '2':
			cout << "Choose C - 0 or C++ - 1 realisation: " << endl;
			r = getch();
			switch (r)
			{
			case '0':
				taskTwoC();
				break;
			case '1':
				taskTwoCPP();
				break;
			default:
				cout << "You enter incorrect number" << endl;
				break;
			}
			break;

		case '3':
			cout << "Choose C - 0 or C++ - 1 realisation: " << endl;
			r = getch();
			switch (r)
			{
			case '0':
				taskThreeC();
				break;
			case '1':
				taskThreeCPP();
				break;
			default:
				cout << "You enter incorrect number" << endl;
				break;
			}
			break;

		case '4':
			cout << "Choose C - 0 or C++ - 1 realisation: " << endl;
			r = getch();
			switch (r)
			{
			case '0':
				taskFourC();
				break;
			case '1':
				taskFourCPP();
				break;
			default:
				cout << "You enter incorrect number" << endl;
				break;
			}
			break;

		case '5':
			cout << "Choose C - 0 or C++ - 1 realisation: " << endl;
			r = getch();
			switch (r)
			{
			case '0':
				taskFiveC();
				break;
			case '1':
				taskFiveCPP();
				break;
			default:
				cout << "You enter incorrect number" << endl;
				break;
			}
			break;

		case 27: exit(0);  break;
		default: cout << "Nothing to do..." << endl;
		}

		cout << endl;
		system("pause");
	}

	return 0;
}