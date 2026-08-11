/* Plain text formatting
-> all alphabet characters surrounded by asterisks will be made upper-case,
-> all characters surrounded by underscores will be separated by additional spaces
-> the symbol (* or _) will be ignored if a matching one isn't found in the sequence
*/

#include <string>
#include <iostream>
#include <algorithm>

void ast_changer(std::string &sentence) {
    for(char c : sentence) {
        std::transform(sentence.begin(), sentence.end(), sentence.begin(), ::toupper);;
    }
}

void und_changer(std::string &sentence) {
    size_t sentence_len = sentence.length();
    for(int i = sentence_len; i > 0; i--) {
        if (sentence[i] == '_') {
            sentence[i] = ' ';
            continue;
        } else if (sentence[i+1] == '_') {
            continue;
        } else {
            sentence[i] += ' ';
        }
    }
}

void apply_und_changes(std::string &sentence, size_t found_und, size_t sentence_len) {
    size_t position_und = -1, end_und = 0;
    for (size_t i = 0; i < sentence_len; i++) {
            position_und = found_und;
            end_und = sentence.find('_', position_und + 1);
            if (end_und != std::string::npos) {
                und_changer(sentence.substr(position_und, end_und));
            }
            found_und = sentence.find('_',  end_und + 1);
        }
}

void apply_ast_changes(std::string &sentence, size_t found_ast, size_t sentence_len) {
    size_t position_ast = -1, end_ast = 0;
    for (size_t i = 0; i < sentence_len; i++) {
            position_ast = found_ast;
            end_ast = sentence.find('_', position_ast + 1);
            if (end_ast != std::string::npos) {
                ast_changer(sentence.substr(position_ast, end_ast));
            }
            found_ast = sentence.find('_',  end_ast + 1);
        }
}


void formatter(std::string &sentence) {
    
    size_t sentence_len = sentence.length();
    size_t found_ast = sentence.find('*');
    size_t found_und = sentence.find('_');
    if (found_ast == std::string::npos && found_und == std::string::npos) {
        std::cout << sentence << std::endl;
        return;
    } else if (found_ast == std::string::npos) {
        apply_und_changes(sentence, found_und, sentence_len);        
    } else if (found_und == std::string::npos) {
        apply_ast_changes(sentence, found_ast, sentence_len);
    } else {
        while (found_und != std::string::npos || found_ast != std::string::npos) {
            size_t tmp_position_und = found_und;
            size_t tmp_position_ast = found_ast;
            
            if (found_und > found_ast) {
                // Asterisk appears first
                found_ast = sentence.find('*', tmp_position_ast + 1);
                found_und = sentence.find('_', tmp_position_und + 1);
                if (found_ast > found_und || found_ast > tmp_position_und) {
                    // Undescore appears before second asterisk
                    // searches next asterisk after the underscore found
                    size_t found_ast = sentence.find('*', tmp_position_und + 1);
                    
                    continue;
                } else {
                    apply_ast_changes(sentence, found_ast, sentence_len);
                }
            } else {
                // Underscore appears first
                size_t found_ast = sentence.find('*', tmp_position_und + 1);
                size_t found_und = sentence.find('_', tmp_position_ast + 1);
                if (found_und > found_ast) {

                } else {
                    apply_und_changes(sentence, found_und, sentence_len);
                }
            }
        }
        
    }
}

int main()
{
    std::string sentence;
    std::getline(std::cin, sentence);

    // manipulate the sentence here
    
    

    std::cout << sentence << "\n";
}