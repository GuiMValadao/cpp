#include <iostream>
#include <string>

using namespace std;

int main(void) {

    string x = "0123";   
    for (int i = 0; i < x.size(); i++) {
        bool ans = x[i] == (i+48);
        cout << ans << endl;
    }
    

}