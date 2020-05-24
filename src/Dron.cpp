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

Lewa.Ustaw(C/3,A/5);
Prawa.Ustaw(C/3,A/5);

SWektor<double,3> Lewy((-A*3/5),(-B*3/5),0);
PozycjaLewa = Lewy;
Lewa.ustaw_pozycje(Lewy);

SWektor<double,3> Prawy((A*3/5),(B*3/5),0);
PozycjaPrawa = Prawy;
Lewa.ustaw_pozycje(Prawy);


SWektor<double,3> tmp(A/2,B/2,C/2);
Punkt0 = tmp;

}

void Dron::ustawAPI(std::share_ptr<drawNS::Draw3DAPI> API) {
Prostopadloscian::ustawAPI(API);
Lewa.ustawAPI(API);
Prawa.ustawAPI(API);
}

void Dron::Obrot(double stopnie) {
MacierzOb Obrot(stopnie);
Orientacja = Orientacja * Obrot;
Lewa.ObrotDR(PozycjaLewa,Obrot,Orientacja);
Prawa.ObrotDR(PozycjaPrawa,Obrot,Orientacja);
}

void Dron::Przesun(double odleglosc, double stopnie) {
SWektor<double,3> przesuniecie(0,odleglosc*cos(stopnie*M_PI/180),odleglosc*sin(stopnie*M_PI/180));



(*this).Orient_wektor(przesuniecie);
Srodek = Srodek + przesuniecie;
Lewa.Przesun(odleglosc,stopnie);
Prawa.Przesun(odleglosc,stopnie);

}

void Dron::Rysuj() {
Rysuj();
Lewa.Rysuj();
Prawa.Rysuj();

}




















