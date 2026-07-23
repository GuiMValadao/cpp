/* Structure of time or time of structure
Declare a structure that handles the time of day with accuracy of one minute.
Asks the user for two inputs, the hour and minute, checks if they are valid times,
assign the enterd values to the declared struct and outputs them.
*/

#include <iostream>

int main(void) {
    struct TIME {
        int hour;
        int minute;
    };

    TIME current_time;
    int hour, minute;
    std :: cout << "What hour is now? ";
    std :: cin >> hour;
    
    std :: cout << "How many minutes passed since this hour started? ";
    std :: cin >> minute;
    
    if (hour > 23 || minute > 59 || hour < 0 || minute < 0) {
        std :: cout << "Incorrect value for hour or minute entered.";
        return -1;
    }
    
    current_time.hour = hour;
    current_time.minute = minute;
    std::cout<<current_time.hour<<":"<<current_time.minute;
    return 0;
}