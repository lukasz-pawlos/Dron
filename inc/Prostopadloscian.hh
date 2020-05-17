#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
#include "Dr3D_gnuplot_api.hh"




class Prostopadloscian :public Bryla {
protected:
    double A;
    double B;
    double C;

    Prostopadloscian();

public:
    Prostopadloscian(double bok_A, double bok_B, double bok_C);

    unsigned int Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api) const override;
    void ustaw_pozycje(const SWektor<double,3> &Wektor) override;
    void ustaw_orientacje(const MacierzOb &Macierz) override;

    void Orient_wektor(SWektor<double,3> &Wek) const;

    void Wspolrzedne(SWektor<double,3>* wsp) const;

};



#endif
