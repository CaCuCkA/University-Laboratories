#include <iostream>
#include <cmath>
#include <locale>

using namespace std;

int main(){
	setlocale(LC_ALL, "Ukranian");

	int argument;
	float a, S, r, R, x ;

	cout << "Напишіть число від 1 до 4: ";
	cin >> argument; 

	cout << "Введіть його значення: ";
	cin >> x;

	switch(argument)
	{
		case 1:
		{
			a = x;
			R = a / sqrt(3);
			r = a / (2 * sqrt(3));
			S = a * a * sqrt(3) / 4;
			break; 
		}
		case 2:
		{
			r = x;
			a = r * 2 * sqrt(3);
			R = a / sqrt(3);
			S = a * a * sqrt(3) / 4;
			break;
		} 
		case 3:
		{
			R = x;
			a = R * sqrt(3);
			r = a / (2 * sqrt(3));
			S = a * a * sqrt(3) / 4;
			break;
		}
		case 4:
		{
			S = x; 
			a = sqrt(S * 4 / sqrt(3));
			R = a / sqrt(3);
			r = a / (2 * sqrt(3));
			break;

		}
		default:
		{
			cout << "Ой... Щось трапилось. Можливо ваше число не входить до проміжку 1 - 4";
			break;
		}
	}

	cout << "a: " << a << endl;
	cout << "r: " << r << endl;
	cout << "R: " << R << endl;
	cout << "S: " << S << endl;

	return 0;

}