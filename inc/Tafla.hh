#ifndef TAFLA_HH
#define TAFLA_HH

#include "Powierzchnia.hh"

class Tafla{
protected:

    int ID = -1;
    std::shared_ptr<drawNS::Draw3DAPI> api;
double bok;
public:


Tafla() = delete;

Tafla (double wymiar);

void Rysuj();
};


#endif
