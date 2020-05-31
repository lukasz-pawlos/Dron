#ifndef SRUBA_HH
#define SRUBA_HH

#include "GraniastoslupSzes.hh"
#include "SWektor.hh"
#include "Macierz.hh"

class Sruba : public GraniastoslupSzes {
protected:

MacierzOb Rotacja;

void Orient_wektor(SWektor <double,3> & Wek)const;

void Wspolrzedne(SWektor <double,3> *Wsp)const;

public:

Sruba();

Sruba(double Abok,double Hbok);

void Ustaw (double Abok,double Hbok);

void ustaw_pozycje(const SWektor<double,3> &Wektor) override;

void ustaw_orientacje(const MacierzOb &Macierz) override;

void Przesun(double odleglosc, double stopnie);

void Obracaj();

void ObrotDR (SWektor <double,3> Ods, MacierzOb Obrot, MacierzOb Ort_Drona);


void Rysuj();

};




#endif
