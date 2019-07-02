#include <iostream>
#include <fstream>
#include <string>
#include "binary_tree.hpp"
#include "pair.hpp"

int main(){
    static const char word_separator = '/';
    static const char char_separator = ' ';


    BinaryTree dict = BinaryTree();

    //reading morse translate file
    std::string line;
    std::ifstream myfile ("morse.txt");
    if (myfile.is_open()){
        std::string delimiter = "\n";
        int index_of_delimiter;
        Pair pair = Pair();
        while ( getline(myfile, line) ){
            index_of_delimiter = line.find(delimiter);
            Pair.set_key(line.substr(index_of_delimiter+1));
            Pair.set_data(0, line.substr(index_of_delimiter));
            dict.add(pair);
        }
        
        //read data from stdin and print data
        std::string phrase;

        std::cin.ignore();
        getline(std::cin, phrase, '\n');
        size_t pos_word;
        size_t pos_char;
        std::string word, morse_char;
        
        while(phrase[0] != '\n'){
            pos_word = 0;
            //phrase manipulation
            while ((pos_word = line.find(word_separator)) != std::string::npos) {
                // pos_word = line.find(word_separator);
                word = line.substr(0, pos_word);
                //word manipulation
                pos_char = 0;
                while ((pos_char = word.find(char_separator)) != std::string::npos) {
                    morse_char = word.substr(0, pos_char);
                    std::cout << binary_tree.find(morse_char);
                    word.erase(0, pos_char + 1);
                }
                std::cout << ' ';
                std::cout << token << std::endl;
                line.erase(0, pos_word + 1);
            }
            std::cout << '\b' <<std::endl; 
            std::cin.ignore();
            getline(std::cin, phrase, '\n');
        }
    } else {
        std::cout << "Failed to open morse.txt" << std::endl;
    }
    return 1;
}