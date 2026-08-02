/* String manipulation: pangrams
A pangram is a sentence that uses all letters of the alphabet at least once. Check if a sentence is a pangram and print
the individual letter count.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    getline(cin, input);

    // Write your code here
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int count[25] = {0};
    bool is_pangram = true;
    for (int letter = 0; letter < input.size(); letter++) {
        if(input[letter] < 'a') {
            input[letter] += 'a'-'A';
        }
        int position = alphabet.find(input[letter]);
        count[position]++;
    }
    for(int i = 0; i < 26; i++) {
        if(count[i] == 0) {
            is_pangram = false;
            break;
        }
    }
    if(is_pangram) {
        cout << "Pangram" << endl;
    } else {
        cout << "Not pangram" << endl;
    }
    for(int j = 0; j < 26; j++) {
        cout << alphabet[j] << "-" << count[j] << endl;
    }
    return 0;
}
