#include "pair.hpp"
Pair::Pair(std::string key, char data){
    mKey = key;
    mData = data;
}

Pair::Pair(){
    mKey = "";
    mData = '\0';
}

std::string Pair::get_key() const{
    return mKey;
}
void Pair::set_key(std::string key){
    mKey = key;
}
void Pair::set_data(char data){
    mData = data;
}
char Pair::get_data() const{
    return mData;
}

Pair::~Pair(){}
