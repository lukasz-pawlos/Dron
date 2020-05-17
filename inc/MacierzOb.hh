#ifndef MACIERZOB_HH
#define MACIERZOB_HH

#include "Macierz.hh"
#include "SWektor.hh"
#include <iostream>

#define PI 3.141592653589

class MacierzOb : public SMacierz<double,3>{
public:

MacierzOb (const SMacierz <double,3> & M);
MacierzOb (){};

MacierzOb (double stopnie);
};

#endif
