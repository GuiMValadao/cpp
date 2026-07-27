/* One step further: finding the lengths of months
Uses the isLeap function to flag if a year is leap and prints the amount of days each month in a year has.
Accounts for leap years, resulting in 29 days for February if it is or 28 if not.
*/

#include <iostream>

using namespace std;
bool isLeap(int year) { 
    
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;

}

int monthLength(int year, int month) {
    if (month < 1 || month > 12) { 
        return 0;
    }
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // Stores the number of days of each month.
    if (isLeap(year)) {
        // if is a leap year, february has one day more
        days[1] += 1;
    }
    return days[month-1];   // first month is 1; first index is 0.
}

int main(void) {

	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr,mo) << " ";
		cout << endl;
	}
	return 0;
}