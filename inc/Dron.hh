#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "SWektor.hh"
#include "Sruba.hh"


class Dron: public Prostopadloscian, public InterfejsDrona{
protected:

Sruba Prawa;
Sruba Lewa;

SWektor<double,3> PozycjaPrawa;
SWektor<double,3> PozycjaLewa;

Dron() = delete;
void Przesun(double odleglosc,double stopnie) override;
void Obrot(double stopnie);

public:


Dron(double bA,double bB, double bC);

void ustawAPI(std::share_ptr<drawNS::Draw3DAPI> API);

void Rysuj();

void Plyn(double odleglosc,double stopnie) override;
void ObrotAnimacja(double stopnie) override;



};



#endif
