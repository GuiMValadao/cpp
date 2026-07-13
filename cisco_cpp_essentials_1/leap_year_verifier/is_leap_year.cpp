#include <iostream>

using namespace std;

int main(void) {
	int year;
	
	cout << "Enter a year: ";
	cin >> year;
	
	if (year < 1582)
	   cout << "Not part of the gregorian calendar.";
	else {
        // The conditions use the fact the 0 is considered as false, while any other number as true. 
	    if (year % 4)   // if not divisible by 4, is common year
	        cout << "Common year";
	    else if (year % 100)    // if not divisible by 100, is leap year
	        cout << "Leap year";
	    else if (year % 400)    // if not divisible by 400, is common year
	        cout << "Common year";
	    else    // all other are leap years
	        cout << "Leap year";
	}

    /*
    // Cisco course sample solution:
    
    if (year < 1582) {
        cout << "Warning: Year falls outside the Gregorian era." << endl;
    } else if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << "Leap year" << endl;
    } else {
        cout << "Common year" << endl;
    }
    */
	
	return 0;
}