#ifndef PDS_LISTA3_CUBO
#define PDS_LISTA3_CUBO

#include <string>
#include "forma3d.h"

class Cubo : public Forma3D {
private:
    std::string mNome, mCor;
    double mLado;
public:
    Cubo(std::string, double);
    virtual std::string get_cor();
    virtual std::string get_nome();
    virtual double get_volume();
};

#endif