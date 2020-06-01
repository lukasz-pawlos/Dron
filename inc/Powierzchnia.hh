#ifndef POWIERZCHNIA_HH
#define POWIERZCHNIA_HH


#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"
using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;


class Powierzchnia {
protected:

    int ID = -1;
    std::shared_ptr<drawNS::Draw3DAPI> api;

public:


virtual void Rysuj() ;

void ustaw_api(std::shared_ptr<drawNS::Draw3DAPI> API) {api =API;};


std::shared_ptr<drawNS::Draw3DAPI> daj_api() const {return api;};

};


#endif
