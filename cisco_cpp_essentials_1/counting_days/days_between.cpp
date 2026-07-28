/* Third step further - counting the days
Calculates total the amount of days between two dates.
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

int daysBetween(Date d1, Date d2) {
	// year d1 can't be after d2.
    if (d1.year > d2.year) {
        return -1;
    }
    // 
    
    // If years are the same, d1.month can't be later than d2; if months are same, d1.day must be after d2.day 
    if (d1.year == d2.year) {
        if (d1.month > d2.month) {
        return -1;
        }
        if (d1.month == d2.month) {
            if (d1.day > d2.day) {
                return -1;
            } else {
                return d2.day - d1.day;
            }
        }
        return dayOfYear(d2) - dayOfYear(d1);
    } 
    int result = 0;
    for (int count_year = d1.year; count_year < d2.year; count_year++) {
        if (isLeap(count_year)) {
            result += 366;
        } else {
            result += 365;
        }
    }
    return result += (dayOfYear(d2) - dayOfYear(d1));
}

int main(void) {

	Date since,to;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> to.year >> to.month >> to.day;
	cout << daysBetween(since,to) << endl;
	return 0;
}