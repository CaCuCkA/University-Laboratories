#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int x, y;

	cout << "Input x: ";
	cin >> x;

	cout << "Input y: ";
	cin >> y;

	if(-4 <= x && x <= 4 && -4 <= y && y <= 4){
	    
		if((x - 2) * (x - 2) + y * y > 4 ){
		    
			cout << "Your point is in range!"; 
		}
		else{
		    
		    cout << "Your point is not in range";
		    
		}
		
	
	}
	return 0;
}