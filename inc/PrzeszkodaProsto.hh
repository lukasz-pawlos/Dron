#ifndef PRZESZKODAPROSTO_HH
#define PRZESZKODAPROSTO_HH

#include "Przeszkoda.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"

class PrzeszkodaProsto: public Prostopadloscian, public Przeszkoda {
protected:

PrzeszkodaProsto() = delete;
public:

PrzeszkodaProsto(double Abok, double Bbok, double Cbok);

bool Kolizja(std::shared_ptr<InterfejsDrona> Inter) const override;

};


#endif
