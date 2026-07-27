/*Second step further: finding day of year
Tells what day of year is the day input.
*/

#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year) { 
    // Flags if a year is leap or not
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

int monthLength(int year, int month) {
    // Returns the length of a month
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

int dayOfYear(Date date) {
    // Returns the number of a day in a year
    int result = 0;
    if (date.month > 1) {
        for (int i = 1; i < date.month; i++) {
            result += monthLength(date.year, i);
        }
    }
    return result += date.day;
}

int main(void) {

	Date d;
	cout << "Enter year, month, day: ";
	cin >> d.year >> d.month >> d.day;
    if (d.month < 1 || d.month > 12 ||d.day < 0 || d.day > 31){
        cout << "Invalid date format entered. Certify you type in the order year month day, with a space between." << endl;
        return -1;
    }
	cout << dayOfYear(d) << endl;
	return 0;
}