/* Text manipulation: eliminate duplicates

This program receives a line of text and removes all duplicated words within each sentence 
(considering a sentence as separated by of of the symbols (. , ! ? ; - :)).
*/

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

// Checks if the word is present in the partial result, which is the smaller sentence within the string of text received
std::string check_word(std::string word, std::string partial_result) {
    if (!word.empty()) {
        if (partial_result.find(word) == std::string::npos) {
            return word + " ";
        }
    }
    return "";
}

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    // manipulate the sentence here
	std::string partial_sentence, partial_result, result, word;
    char sentence_separators[] = {'.', ',', '!', '?', ';', '-', ':'}, current_separator = ' ';
    int size_separators = sizeof(sentence_separators) / sizeof(sentence_separators[0]);
    bool end_sentence = false;
    int count_chars = 0;
    
    for (char c : sentence) {
        count_chars++;  // To keep track and allow sentences with no pontuation at the end

        for (int i = 0; i < size_separators; i++) {
            // Checks the first occurence of one of the sentence separators defined above
            if(i == 0) {
                // Adds the current character to the current sentence irrespective of the separator
                partial_sentence += c;
            }
            if(c == sentence_separators[i]) {
                // If a separator is found, records which one it is and finishes the current sentence
                current_separator = sentence_separators[i];
                end_sentence = true;
                break;
            } 
            else if (count_chars == sentence.length()) {
                // If the current character is the last from the string, ends the sentence
                current_separator = '\0';
                end_sentence = true;
                break;
            }
        }
        while (end_sentence) {
            // If a full sentence was obtained, separates the words and adds to result if they're not duplicate
            for (char d : partial_sentence) {
                if (std::isalpha(d) || d == current_separator || d == '\0') {
                    // Adds the current char from the partial sentence to the current word
                    word += std:: tolower(d);
                } else {
                    // If a space was reached, checks if the word is already on the partial result and clears the world
                    partial_result += check_word(word, partial_result);
                    word.clear();
                }
            }
            // Addsthe partial rseult to the final rseult and clears both partial result and current sentence
            result += partial_result;
            partial_result.clear();
            partial_sentence.clear();
            end_sentence = false;
        }
        // Checks the last world, as the above condition will skip it
        result += check_word(word, partial_result);
        word.clear();   
    }  

    std::cout << result << "\n";
}