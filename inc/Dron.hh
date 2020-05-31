#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "SWektor.hh"
#include "Sruba.hh"


class Dron: public Prostopadloscian, public InterfejsDrona{
protected:

Dron() = delete;
Sruba Prawa;
Sruba Lewa;

SWektor<double,3> PozycjaPrawa;
SWektor<double,3> PozycjaLewa;


public:
Dron(double bA,double bB, double bC);

void ustaw_api(std::shared_ptr<drawNS::Draw3DAPI> API);


void Rysuj() override;
void Obrot(double stopnie) override;
void Przesun(double odleglosc,double stopnie) override;
void Plyn(double odleglosc,double stopnie) override;
void ObrotA(double stopnie) override;


};



#endif
