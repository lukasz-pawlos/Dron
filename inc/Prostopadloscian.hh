#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "MacierzOb.hh"


class Prostopadloscian :public Bryla {
protected:
    double A;
    double B;
    double C;

    Prostopadloscian();

public:
    Prostopadloscian(double bok_A, double bok_B, double bok_C);

    void Rysuj() override;
    void ustaw_pozycje(const SWektor<double,3> &Wektor);
    void ustaw_orientacje(const MacierzOb &Macierz);
    void ustaw_srodek(double X, double Y, double Z);

    void Orient_wektor(SWektor<double,3> &Wek) const;

    void Wspolrzedne(SWektor<double,3> *wsp) const;

};



#endif
