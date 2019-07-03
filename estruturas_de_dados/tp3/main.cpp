#include <iostream>
#include <fstream>
#include <string>
#include "binary_tree.hpp"
#include "pair.hpp"

int main(){
    static const std::string word_separator = "/ ";
    static const char char_separator = ' ';


    BinaryTree *dict = new BinaryTree();

    //reading morse translate file
    std::string line;
    std::ifstream myfile ("morse.txt");
    if (myfile.is_open()){
        std::string delimiter = " ";
        int index_of_delimiter;
        Pair pair = Pair();
        while (getline(myfile, line) ){
            index_of_delimiter = line.find(delimiter);
            pair.set_key(line.substr(index_of_delimiter+1));
            pair.set_data(line[0]);
            dict->add(pair);
        }
        // std::cout << dict->find(".") << std::endl;
        
        
        //read data from stdin and print data
        std::string phrase;

        std::cin.ignore();
        // getline(std::cin, phrase, '\n');
        getline(std::cin, phrase);
        size_t pos_word;
        size_t pos_char;
        std::string word, morse_char;
        
        while(phrase.length() != 0){
            // std::cout << phrase[0] << " -- phrase.length: " << phrase.length() << std::endl;     
            
            pos_word = phrase.find(word_separator);

            while(pos_word != std::string::npos){
                word = phrase.substr(0, pos_word);
                pos_char = word.find(char_separator);

                while(pos_char != std::string::npos){
                    morse_char = word.substr(0, pos_char);
                    std::cout << dict->find(morse_char);
                    word.erase(0, pos_char+1);
                    pos_char = word.find(char_separator);
                }
                std::cout << dict->find(word) << " ";

                phrase.erase(0, pos_word+2);
                pos_char = word.find(word_separator);
                if(pos_char == std::string::npos)
                    break;
            }
            // word = phrase.substr(0, pos_word);
            pos_char = phrase.find(char_separator);
            if(pos_char != std::string::npos){
                while(pos_char != std::string::npos){
                    morse_char = phrase.substr(0, pos_char);
                    std::cout << dict->find(morse_char);
                    phrase.erase(0, pos_char+1);
                    pos_char = phrase.find(char_separator);
                }
                std::cout << dict->find(phrase) << std::endl;
            } else {
                std::cout << dict->find(phrase) << std::endl;
            }
            
            std::cin.ignore();
            getline(std::cin, phrase);
        }
        dict->print();
        delete dict;
    } else {
        std::cout << "Failed to open morse.txt" << std::endl;
    }
    return 1;
}