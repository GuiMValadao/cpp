/* Collecting banknotes
Find the minimal number of banknotes needed to deliver any amount of money to the client
and print the value of each note required. The values of the notes are 50, 20, 10, 5 and 1
*/
#include <iostream>

using namespace std;
int main(void) {
    int money_amount;
    int note_values[] = {50, 20, 10, 5, 1};
    cout << "How much money will you withdraw? ";
    cin >> money_amount;
    if (money_amount < 1) {
        cout << "Invalid amount typed. No withdrawal done." << endl;
        return -1;
    }
    
    for (int i = 0; i < 5; i++) {
        int current_value = note_values[i];
        while (money_amount >= current_value) {
            cout << current_value << " ";
            money_amount -= current_value;
        }
    }
    return 0;
}