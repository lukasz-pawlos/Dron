#ifndef GRANIASTOSLUPSZES_HH
#define GRANIASTOSLUPSZES_HH

#include "Bryla.hh"
#include "SWektor.hh"
#include "Macierz.hh"


class GraniastoslupSzes : public Bryla {
protected:

double A;
double H;

GraniastoslupSzes();

void Wspolrzedne(SWektor<double,3>* wsp) const;

void Orient_wektor(SWektor<double,3> &Wek) const override;

public:

    void ustaw_pozycje(const SWektor<double,3> &Wektor);
    void ustaw_orientacje(const MacierzOb &Macierz);

GraniastoslupSzes(double Abok, double Hbok);

void Rysuj()override;

};

#endif
