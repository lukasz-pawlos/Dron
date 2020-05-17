#include "Dron.hh"

Dron::Dron(double bA, double bB, double bC) {

if(A < 0){
    cout << "Bok nie moze byc wartoscia ujemna" << endl;
    exit(1);
}

if(B < 0){
    cout << "Bok nie moze byc wartoscia ujemna" << endl;
    exit(1);
}

if(C < 0){
    cout << "Bok nie moze byc wartoscia ujemna" << endl;
    exit(1);
}
A = bA;
B = bB;
C = bC;

SWektor<double,3> tmp(A/2,B/2,C/2);
Punkt0 = tmp;

}

void Dron::Obrot(double stopnie) {
MacierzOb Obrot(stopnie);
Orientacja = Orientacja * Obrot;

}

void Dron::Przesun(double odleglosc, double stopnie) {
SWektor<double,3> przesuniecie(0,odleglosc*cos(stopnie*M_PI/180),odleglosc*sin(stopnie*M_PI/180));



(*this).Orient_wektor(przesuniecie);

Srodek = Srodek + przesuniecie;
}
