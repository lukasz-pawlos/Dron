#ifndef BRYLA_HH
#define BRYLA_HH

#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


class Bryla{
protected:
    SWektor<double,3> Srodek;
    MacierzOb Orientacja;

    int ID = -1;
    std::shared_ptr<drawNS::Draw3DAPI> api;

    static int liczba_obiektow_obecnych;
    static int liczba_obiektow_stworzonych;


    Bryla() { ++liczba_obiektow_obecnych; ++liczba_obiektow_stworzonych;};
    Bryla(std::shared_ptr<drawNS::Draw3DAPI> API) {++liczba_obiektow_obecnych; ++liczba_obiektow_stworzonych; api = API;}
    virtual void Orient_wektor(SWektor<double,3> &Wek) const =0;

public:


~Bryla() {--liczba_obiektow_obecnych; }
virtual void Rysuj() = 0;
void ustaw_pozycje(const SWektor<double,3> &Wektor) {Srodek = Wektor;};

void ustaw_pozycje(double X,double Y, double Z) {Srodek[0]=X; Srodek[1]=Y; Srodek[2]=Z;};

virtual void ustaw_orientacje(const MacierzOb &Macierz) {Orientacja = Macierz;};

void ustaw_api(std::shared_ptr<drawNS::Draw3DAPI> API) {api =API;};

SWektor<double,3> daj_srodek() const {return Srodek;};

MacierzOb daj_orientacje() const {return Orientacja;};

std::shared_ptr<drawNS::Draw3DAPI> daj_api() const {return api;};

static int daj_liczba_obecnych() {return liczba_obiektow_obecnych;}
static int daj_liczba_stworzonych() {return liczba_obiektow_stworzonych;}
};






#endif
