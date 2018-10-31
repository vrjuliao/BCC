#ifndef PDS_LISTA3_FORMA
#define PDS_LISTA3_FORMA

#include <string>

class Forma {
public:
    virtual std::string get_cor() = 0;
    virtual std::string get_nome() = 0;
};

#endif