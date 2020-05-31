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


    Bryla() {};
public:

virtual void Rysuj() = 0;
virtual void ustaw_pozycje(const SWektor<double,3> &Wektor) = 0;
virtual void ustaw_orientacje(const MacierzOb &Macierz) =0;
virtual void Orient_wektor(SWektor<double,3> &Wek) const =0;

void ustaw_api(std::shared_ptr<drawNS::Draw3DAPI> API) {api =API;};
SWektor<double,3> daj_srodek() const {return Srodek;};
MacierzOb daj_orientacje() const {return Orientacja;};

std::shared_ptr<drawNS::Draw3DAPI> daj_api() const {return api;};
};



#endif
