/* Times and durations
Receives a start time and a end time and outputs the total duration.
*/

#include <iostream>

struct TIME {
        int hour;
        int minute;
    };


int main(void) {

    TIME begin;
    TIME end;
    int hour_duration, minute_duration;

    // Get user inputs
    std :: cout << "At what hour did it start? ";
    std :: cin >> begin.hour;
    
    std :: cout << "At which minute did it start? ";
    std :: cin >> begin.minute;
    
    std :: cout << "At what hour did it end? ";
    std :: cin >> end.hour;
    
    std :: cout << "At which minute did it end? ";
    std :: cin >> end.minute;

    // Checks if enterd time is valid (hour from 0 to 24 and minutes from 0 to 59; and end time after start time)
    if ((begin.hour > 23) || (end.hour > 23) || (begin.minute > 59) || (end.minute > 59) || (begin.hour < 0) || (end.hour < 0) 
    || (begin.minute < 0) || (end.minute < 0) || (begin.hour > end.hour) || ((begin.hour == end.hour) && (begin.minute > end.minute))) {
        std :: cout << "Incorrect value for hour or minute entered.";
        return -1;
    }
    
    // Calculates the duration
    hour_duration = end.hour - begin.hour;
    if (begin.minute <= end.minute) {
        minute_duration = end.minute - begin.minute;
    } else {
        // If end minute is smaller than starting minute, detracts one hour and calculates the minute by
        // counting how many minutes passed in the start hour and suming to the how many minutes passed in the ending hour
        hour_duration--;
        minute_duration = (60 - begin.minute) + end.minute;
    }

    // Shows the result
    std::cout<<hour_duration<<":"<<minute_duration;
    
    return 0;
}