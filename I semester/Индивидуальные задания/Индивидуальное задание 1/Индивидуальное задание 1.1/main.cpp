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

    cout << "����i�� �������� a: ";
    cin >> a;

    cout << "����i�� �������� b: ";
    cin >> b;

    cout << "����� ��������: ";
    cin >> ExactValue;

    fstream fs;
    fs.open(path, fstream::app);

    cout << "�i�i���������� �������: (sin(x))^2 + 1" << endl;
    cout << "����i���: [" << a << "," << b << "]" << endl;
    cout << "����� �������� i��������: " << ExactValue << endl;

    fs << "�i�i���������� �������: " << endl << "����i���: [" << a << "," << b << "]" << endl << "����� �������� i��������: " << ExactValue << endl;

    for(int t=10; t <= 100; t += 10){
        n += 10;
        cout << "n=" << n << "\t" <<  "\t" << RightTriangle(a, b, n) << "\t" << "\t" << RightTriangle(a, b, n) - ExactValue << endl;
        fs << "n=" << n << "\t" <<  "\t" << RightTriangle(a, b, n) << "\t" << "\t" << RightTriangle(a, b, n) - ExactValue  << endl;
    }

    fs << "" << endl;
    fs.close();
    return 0;

}
