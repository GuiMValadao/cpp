/* Text manipulation: anagrams
Checks if two received words are anagrams
*/
#include <iostream>
#include <string>
#include <algorithm>

int main(void) {

    // Get two words
    std::string word1, word2;
    std::cin >> word1;
    std::cin >> word2;

    // Turn both words to lowercase
    std::transform(word1.begin(), word1.end(), word1.begin(), ::tolower);
    std::transform(word2.begin(), word2.end(), word2.begin(), ::tolower);

    // Checks if the letters from the first word are found on the second
    // If not, ends the loop and turns word2 to False, in case it became empty earlier
    // If the letter is found, delete it from word2.
    bool is_anagram = true;
    for(char c : word1) {
        size_t found = word2.find(c);
        if(found == std::string::npos) {
            is_anagram = false;
            break;
        }
        word2.erase(found, 1);
    }
    // If word 2 is empty now, both words had same letters.
    if (is_anagram && word2.empty()) {
        std::cout << "anagrams";
    } else {
        std::cout << "not anagrams";
    }
    

    return 0;
}


// Sample solution - using sort() from algorithms library instead of coding it directly in C++.
// This allows O(nlogn) efficiency, while my solution above requires O(n²). Another difference
// is that my solution destroys word2, which, with some adjustments, might help if is necessary
// to know which the characters are mismatched.
// #include <string>
// #include <iostream>
// #include <algorithm>

// bool are_anagarams(std::string &word_a, std::string const &word_b)
// {
//   std::string a = word_a;
//   std::transform(a.begin(), a.end(), a.begin(), ::tolower);

//   std::string b = word_b;
//   std::transform(b.begin(), b.end(), b.begin(), ::tolower);

//   std::sort(a.begin(), a.end());
//   std::sort(b.begin(), b.end());

//   return a == b;
// }

// int main()
// {
//     std::string word_a, word_b;

//     std::cin >> word_a;
//     std::cin >> word_b;

//     std::cout << (are_anagarams(word_a, word_b) ? "anagrams" : "not anagrams" ) << "\n";
// }