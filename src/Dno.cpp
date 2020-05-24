#include "Dno.hh"

Dno:Dno(double wymiar) {
SWektor<double,3> W(0,0,(-1*wymiar));
Srodek = W;
bok = wymiar;
string K = "yellow";
kolor = K;

}
