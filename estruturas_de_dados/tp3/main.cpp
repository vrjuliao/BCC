#include <iostream>
#include <fstream>
#include <string>

#include "binary_tree.hpp"
#include "pair.hpp"

int main(int argc, char const *argv[]){
    static const std::string WORD_SEPARATOR = " / ";
    static const char CHAR_SEPARATOR = ' ';
    bool print_pre_order = false;
    if(argc == 2){
        std::string arg = argv[1];
        if(arg == "-a"){
            print_pre_order = true;
        } else {
            std::cout << "Error: Incorrect Params: only expected parameter is \"-a\"" << std::endl;
            return 0;
        }
    } else if(argc > 2){
        std::cout << "Error: Incorrect Params: quantity of parameters incorrect" << std::endl;
        return 0;
    }



    //reading morse translate file
    std::string line;
    std::ifstream myfile ("morse.txt");
    if (myfile.is_open()){
        std::string delimiter = " ";
        int index_of_delimiter;
        Pair pair = Pair();
        BinaryTree *dict = new BinaryTree();

        try{
            while (getline(myfile, line) ){
                index_of_delimiter = line.find(delimiter);
                pair.set_key(line.substr(index_of_delimiter+1));
                pair.set_data(line[0]);
                dict->add(pair);
            }
        
        
            //read data from stdin and print data
            std::string phrase;

            size_t pos_word;
            size_t pos_char;
            std::string word, morse_char;
            bool print_blank_line = false;

            //for each line in input, split ir by respective separator
            //after split operation, translate using <BinaryTree dict>
            while(getline(std::cin, phrase) && phrase.length()){
                print_blank_line = true;
                //split a string by separator " / "
                pos_word = phrase.find(WORD_SEPARATOR);

                //each peace will be spitted by separator ' '
                //the token gived is a morse char
                while(pos_word != std::string::npos){
                    word = phrase.substr(0, pos_word);
                    pos_char = word.find(CHAR_SEPARATOR);

                    while(pos_char != std::string::npos){
                        morse_char = word.substr(0, pos_char);
                        std::cout << dict->find(morse_char);
                        word.erase(0, pos_char+1);
                        pos_char = word.find(CHAR_SEPARATOR);
                    }
                    //the rest of word is a morse char too
                    // because in the final of word no have a char separator
                    std::cout << dict->find(word) << ' ';

                    phrase.erase(0, pos_word+3);
                    pos_word = phrase.find(WORD_SEPARATOR);
                }

                //the rest of phrase is a morse word too
                //because in the final of phrase no have a word separator
                //so the same proccess to obtain a word is needed
                pos_char = phrase.find(CHAR_SEPARATOR);
                if(pos_char != std::string::npos){
                    while(pos_char != std::string::npos){
                        morse_char = phrase.substr(0, pos_char);
                        std::cout << dict->find(morse_char);
                        phrase.erase(0, pos_char+1);
                        pos_char = phrase.find(CHAR_SEPARATOR);
                    }
                    std::cout << dict->find(phrase) << std::endl;
                } else {
                    std::cout << dict->find(phrase) << std::endl;
                }
            }
            if(print_pre_order){
                if(print_blank_line)
                    std::cout << std::endl;
                dict->print();
            }
        } catch (std::exception &e){
            std::cout << e.what() << std::endl;
        }
        delete dict;
    } else {
        std::cout << "Failed to open morse.txt" << std::endl;
    }
    return 1;
}