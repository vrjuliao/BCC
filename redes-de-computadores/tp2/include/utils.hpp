#ifndef UTILS_TP2_REDES
#define UTILS_TP2_REDES

#include <exception>
#include <string>

class InitSocketException: virtual public std::exception {
    private:
    std::string msg;

    public:
    InitSocketException(const char *msg);
    const char *what() const throw();

};

// Common attributes
class Utils{
    public:
        static int IPVERSION;
        static const int IPV4 = 4;
        static const int IPV6 = 6;
        static const int MAX_BUFFER_SIZE = 1024;
        Utils();
};

#endif