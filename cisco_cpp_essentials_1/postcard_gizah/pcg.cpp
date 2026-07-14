// Postcard from Gizah
#include <iostream>

using namespace std;
int main(void){
    int h, n, N = 3; // h is height, n is a number indicating one pyramid and N is the maximum number of pyramids
    int base = 16; // Reserve total available space for each pyramid

    // Geting pyramid height
    cout << "h = ";
    cin >> h;

    // Verifying if input was appropriate
    if (h <= 2 || h >= 9) {
        cout << "Invalid height informed. Aborting execution." << endl;
        return -1;
    }

    // Starting drawing loop
    for (int row = 0; row < h; row++){  // Each row

        for (int i = 1; i < N * base+1; i++) {  // Each position in a row
            
            // Checks which pyramid the current position belongs to
            for (int j = 1; j <= N; j++){
                if (i < j * base) {
                    n = (j - 1);
                    break;
                }
            }
            
            // Checks the position and either draws an asterisk or leaves a blank space
            if (i == (h - row + n * base) || i == (h + row + n * base) || 
            (row == h-1 && (i > (h - row + n * base) && i < (h + row + n * base)))) {
                cout << "*";
            }
            else
                cout << " ";      
        }
        cout << endl;
    }
    return 0;
}