#ifndef SRUBA_HH
#define SRUBA_HH

#include "GraniastoslupSzes.hh"
#include "SWektor.hh"

class Sruba : public GraniastoslupSzes {
protected:

MacierzOb Rotacja;

void Orient_wektor(SWektor <double,3> & Wek)const;

void Wspolrzedne(SWektor <double,3> *Wsp)const;

public:

Sruba();

Sruba(double Abok,double Hbok);

void Ustaw (double Abok,double Hbok);

void Przesun(double odleglosc, double stopnie);

void Obracaj();

void ObrotDR (SWektor <double,3> Ods, MacierzOb Obrot, MacierzOb Ort_Drona);

unsigned int Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api):

};




#endif
