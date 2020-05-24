#ifndef INTERFEJSDRONA_HH
#define INTERFEJSDRONA_HH

#include <math.h>
#include "MacierzOb.hh"
#include "SWektor.hh"


class InterfejsDrona {
protected:

InterfejsDrona(){};

public:

virtual void Obrot(double stopnie) = 0;
virtual void Przesun(double odleglosc,double stopnie) =0;
virtual void Plyn(double odleglosc,double stopnie) =0;
virtual void ObrotAnimacja(double stopnie) = 0;
};



#endif // INTERFEJSDRONA_HH
