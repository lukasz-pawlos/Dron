#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "SWektor.hh"


class Dron: public Prostopadloscian, public InterfejsDrona{
public:

Dron() = delete;

Dron(double bA,double bB, double bC);

void Obrot(double stopnie) override;
void Przesun(double odleglosc) override;


};



#endif
