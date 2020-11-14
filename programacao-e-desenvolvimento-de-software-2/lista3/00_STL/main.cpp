#include <map>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main(void){
    std::cout.precision(2);
    std::map<std::string, int> words_map;
    float number_total_words;
    std::string linha, palavra;
    std::istringstream stream;
    
    
    while (std::getline(std::cin, linha)) {
        stream = std::istringstream(linha);
        if(linha == "sair") break;
        while (std::getline(stream, palavra, ' ')) {
            number_total_words++;
            if(words_map.count(palavra) == 0){
                words_map[palavra] = 0;
            }
            words_map[palavra]++;
        }
    } 
    for (std::pair<std::string, int> pair : words_map) {
        std::cout << pair.first << " " << pair.second << " " << pair.second/number_total_words;
        std::cout << std::endl;
    }
}