/* Using pseudorandom valus - a little lottery
The code takes two values from user, a max number and the number of 
values to "draw". Then it draws 'random' numbers using rand(), being 
careful about not drawing the same values twice.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void) {
	int maxball;
	int ballsno;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
    if (ballsno < maxball) {
        cout << "You have chosen less values to drawn than available." << endl;
        return 1;
    }
	srand(time(NULL));

	// Insert your code here
	int rnd, *drawn_balls, draw_num = 0;
    bool drawn;
	drawn_balls = new int[ballsno];

    // Initialie the array with 0's
	for(int i = 0; i < ballsno; i++) {
	    drawn_balls[i] = 0;
	}

    // Keep drawing untill all necessary numbers are drawn
	while(draw_num < ballsno) {
	    rnd = rand() % maxball + 1; // draw a random number
        drawn = true;   // a value was drawn
	    // Iterate over the drawn_balls to check if the value is unique
        for(int j = 0; j < ballsno; j++) {
	        // If the value was already drawn, set's drawn to false and restarts the current draw
            if(rnd == drawn_balls[j]) {
	            drawn = false;
	            break;
	        }
	    }
        // If drawn is still true, then the value was unique. 
        // This prints it, inserts into the array of drawn_balls and add to the
        // amount of drawn balls, which dictates up to when the loop runs
	    if(drawn) {
            cout << rnd << " ";
            drawn_balls[draw_num] = rnd;
            draw_num++;
            
        }
    }
    delete [] drawn_balls;  // Free the memory allocated to the drawn_balls
    cout << endl;
	return 0;
}