#include <iostream>
#include <cmath>

using namespace std;

int main(){

	int x;
	float y;

	cout << "Input x: ";
	cin >> x;

	if(-9 < x && x <= 9 && 0 < x && x != 1){
	
		y = (log(10) / log(x)) / fabs(x * x + 3);
		cout << "In range";
		
	}
	
	else{
	    
		y = exp(x*x*x);
		cout << "Not in range" << endl;
	}
	

	cout << "Y equels: " << y << endl;

	return 0; 

}