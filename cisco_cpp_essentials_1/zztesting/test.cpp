#include <iostream>

using namespace std;
int main(void) {

    int variable, *ptr;
    
    ptr = NULL;
    cout << ptr << endl;

    variable = 5;

    ptr = &variable;
    cout << ptr << " stores " << variable << endl; 
    
    cout << "dereferece : " << *ptr << endl;

    cout << "changing the value the pointer is pointing declaring *ptr = 12" << endl;
    *ptr = 12;

    cout << "New value is " << *ptr << " and the variable now stores " << variable << endl;
    cout << "The location is still " << ptr;
    return 0;

}