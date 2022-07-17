#include <iostream>
#include <cmath>
#include <locale>
#include <fstream>

using namespace std;

double f(double x);

double RightTriangle(double a, double b, int n);

int main(){

    double a, b, ExactValue;
    int n = 0;
    string path = "YakovkinOut.txt";

    setlocale(LC_ALL, "Ukrainian");

    cout << "Введiть значення a: ";
    cin >> a;

    cout << "Введiть значення b: ";
    cin >> b;

    cout << "Точне значення: ";
    cin >> ExactValue;

    fstream fs;
    fs.open(path, fstream::app);

    cout << "Пiдiнтегральна функція: (sin(x))^2 + 1" << endl;
    cout << "Промiжок: [" << a << "," << b << "]" << endl;
    cout << "Точне значення iнтегралу: " << ExactValue << endl;

    fs << "Пiдiнтегральна функція: " << endl << "Промiжок: [" << a << "," << b << "]" << endl << "Точне значення iнтегралу: " << ExactValue << endl;

    for(int t=10; t <= 100; t += 10){
        n += 10;
        cout << "n=" << n << "\t" <<  "\t" << RightTriangle(a, b, n) << "\t" << "\t" << RightTriangle(a, b, n) - ExactValue << endl;
        fs << "n=" << n << "\t" <<  "\t" << RightTriangle(a, b, n) << "\t" << "\t" << RightTriangle(a, b, n) - ExactValue  << endl;
    }

    fs << "" << endl;
    fs.close();
    return 0;

}
