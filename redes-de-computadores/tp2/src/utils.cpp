#include "utils.hpp"


InitSocketException::InitSocketException(const char* msg): std::exception(){
    this->msg = std::string(msg);
}

const char *InitSocketException::what() const throw(){
    return this->msg.c_str();
}

Utils::Utils(){}