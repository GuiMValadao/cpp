/* Calculator - realizes basic math operations*/
#include <iostream>

using namespace std;
int main(void) {
    int n1, n2, continuing = 1;;
    while(continuing){
        cout << "MENU:" << endl << "\n";
        cout << "0 - exit" << endl << "\n";
        cout << "1 - addition" << endl << "\n";
        cout << "2 - subtraction" << endl << "\n";
        cout << "3 - multiplication" << endl << "\n";
        cout << "4 - division" << endl << "\n";
        cout << "Your choice? ";
        cin >> continuing;
        
        if (continuing == 0)
            break;
        
        cout << "Enter the first number: ";
        cin >> n1;
        cout << "Enter the second number: ";
        cin >> n2;
        switch (continuing) {
            case 1: cout << n1 << " + " << n2 << " = " << n1 + n2 << endl; break;
            case 2: cout << n1 << " - " << n2 << " = " << n1 - n2 << endl; break;
            case 3: cout << n1 << " * " << n2 << " = " << n1 * n2 << endl; break;
            case 4:{
                if (n2 == 0) 
                    cout << "Division by zero is undefined." << endl;
                else
                    cout << n1 << " / " << n2 << " = " << n1 / n2 << endl;
                break;
            }
            default: cout << "Invalid choice" << continuing << endl;
        }
    }
    return 0;
}