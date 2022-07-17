#include <iostream>
#include <string>
#include <locale>

using namespace std;

int main(){
	
	setlocale(LC_ALL, "Ukranian");

	int colour;

	string introduction("Червоний: 1; \nПомаранчевий: 2; \nЖовтий: 3; \nЗелений: 4; \nГолубий: 5; \nСиній: 6; \nФіолетовий.");
    
    cout << introduction;
    
	cout << "Привіт! Введіть, будь ласка, значення кольору стрічки: " << endl;
	cin >> colour;

	

	switch(colour)
	{
		case 1: case 2: case 3: cout << "Теплий"; break;
		case 4: case 5: case 6: case 7: cout << "Холодний"; break;
	    default:cout << "Ой... Щось не те. Спробуйте ще раз!"; break;
	}

	return 0;
}