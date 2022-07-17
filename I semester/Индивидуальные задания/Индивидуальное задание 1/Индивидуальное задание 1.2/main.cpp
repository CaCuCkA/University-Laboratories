#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double ValueX(double);

int main(){
    string str;
    int n = 0;
    double x, temp_x;
    double FunctionValue, temp_FunctionValue;
    double a = 100.0, b = 0.0;
    double sum;
    string path = "YakovkinIn.txt";
    ifstream FileWithValue(path);

    if(!FileWithValue.is_open()){
        cout << "Error. File closed!";
    }

    else{


        while(FileWithValue >> x && FileWithValue >> FunctionValue){
            temp_x = x;
            temp_FunctionValue = FunctionValue;

            if(a > temp_x){
                a = temp_x;
            }

            if(b < temp_x){
                b = temp_x;

            n++;
            }
        }
        FileWithValue.close();

        double h = (b - a) / n;

        FileWithValue.open(path);

        for(int i=0; i <= n - 1; i++){
            FileWithValue >> x >> FunctionValue;
            temp_FunctionValue = FunctionValue;
            if(ValueX(temp_FunctionValue) == a){
                temp_FunctionValue = 0;
            }

            sum += h * temp_FunctionValue;
        }


    }


    cout << "Integration interval: " << "[" << a << ", " << b << "]" << endl;
    cout << "Function: " << sum;
    FileWithValue.close();

    return 0;


}
