#ifndef PDS_LISTA3_ESFERA
#define PDS_LISTA3_ESFERA

#include <string>
#include "forma3d.h"

class Esfera : public Forma3D {
private:
    std::string mNome, mCor;
    double mRaio;
public:
    Esfera(std::string, double);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_volume();
};
#endif