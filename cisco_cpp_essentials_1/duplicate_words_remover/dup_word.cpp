#include <string>
#include <iostream>
#include <sstream>
#include <cctype>

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    // manipulate the sentence here
	std::string partial_sentence, partial_result, result, word;
    char sentence_separators[] = {'.', ',', '!', '?', ';', '-', ':'}, current_separator = ' ';
    int size_separators = sizeof(sentence_separators) / sizeof(sentence_separators[0]);
    bool end_sentence = false;
    
    
    for (char c : sentence) {
        for (int i = 0; i < size_separators; i++) {
            if(i == 0) {
                partial_sentence += c;
            }
            if(c == sentence_separators[i] || end_sentence) {
                current_separator = sentence_separators[i];
                end_sentence = true;
                break;
            }
        }
        while (end_sentence) {
            for (char d : partial_sentence) {
                if (std::isalpha(d) || d == current_separator) {
                    word += std:: tolower(d);
                } else {
                    if (!word.empty()) {
                        if (partial_result.find(word) == std::string::npos) {
                            partial_result += word + " ";
                        }
                        word.clear();
                    }
                }
            }
            result += partial_result;
            partial_result.clear();
            partial_sentence.clear();
            end_sentence = false;
        }
        // 
        
    }  
    if (!word.empty()) {
        if (partial_result.find(word) == std::string::npos) {
            result += word + " ";
        }
    }

    std::cout << result << "\n";
}