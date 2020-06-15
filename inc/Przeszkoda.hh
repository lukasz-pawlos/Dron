#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

#include "InterfejsDrona.hh"
#include <memory>

class Przeszkoda {
protected:
public:

virtual bool Kolizja(std::shared_ptr<InterfejsDrona> Inter)const =0;

};

#endif
