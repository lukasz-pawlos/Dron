#ifndef DNO_HH
#define DNO_HH

#include "Powierzchnia.hh"

class Dno {
protected:

    int ID = -1;
    std::shared_ptr<drawNS::Draw3DAPI> api;
double bok;

public:


Dno() = delete;

Dno (double wymiar);

void Rysuj() ;

};


#endif
