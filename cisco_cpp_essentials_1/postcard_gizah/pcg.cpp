#include <iostream>

using namespace std;
int main(void){
    int h, n, N = 3;
    int base = 15; // Reserve total available space for each pyramid
    bool flag;

    cout << "h = ";
    cin >> h;
    if (h <= 2 || h >= 9) {
        cout << "Invalid height informed. Aborting execution." << endl;
        return -1;
    }
    for (int row = 0; row < h; row++){

        for (int i = 1; i < 3 * base+1; i++) {
            if (i < base)
                n = 0;
            else if (i < 2*base)
                n = 1;
            else
                n = 2;

            flag = false;
            if (i == (h - row + n * base) || i == (h + row + n * base) || 
            (row == h-1 && (i > (h - row + n * base) && i < (h + row + n * base)))) {
                cout << "*";
                flag = true;
            }
            if (!flag)
                cout << " ";   
            
        }   
        cout << endl;
    }
    return 0;
}