#include "utils.hpp"


InitSocketException::InitSocketException(const char* msg): std::exception(){
    this->msg = std::string(msg);
}

const char *InitSocketException::what() const{
    return this->msg.c_str();
}