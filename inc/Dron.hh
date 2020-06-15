#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "SWektor.hh"
#include "Sruba.hh"
#include "Przeszkoda.hh"
#include <memory>


class Dron:public InterfejsDrona, public Prostopadloscian, public Przeszkoda, public std::enable_shared_from_this<Dron>{
protected:

Dron() = delete;
Sruba Prawa;
Sruba Lewa;

SWektor<double,3> PozycjaPrawa;
SWektor<double,3> PozycjaLewa;

std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;

static int liczba_dronow;

public:
Dron(double bA,double bB, double bC);

~Dron() {--liczba_dronow; }

void ustaw_api(std::shared_ptr<drawNS::Draw3DAPI> API);


void Rysuj() override;

void ustaw_kolekcje_przeszkod( std::vector<std::shared_ptr<Przeszkoda> > kolekcja);

void Obrot(double stopnie) override;
void Przesun(double odleglosc,double stopnie) override;
void Plyn(double odleglosc,double stopnie) override;
void ObrotA(double stopnie) override;
void Przesun(double X, double Y, double Z) override;

bool Kolizja(std::shared_ptr<InterfejsDrona> Inter)const override;


};



#endif
