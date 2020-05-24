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
    SWektor<double,3> Punkt0;
    MacierzOb Orientacja;

  //  std::shared_ptr<drawNS::Draw3DAPI> api;

    Bryla() {};
public:

virtual unsigned int Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api) const = 0;
virtual void ustaw_pozycje(const SWektor<double,3> &Wektor) = 0;
virtual void ustaw_orientacje(const MacierzOb &Macierz) =0;

//void set_api(std::share_ptr<drawNS::Draw3DAPI> API) {api = API; }
};



#endif
