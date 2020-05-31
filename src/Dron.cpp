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

Lewa.Ustaw(C/1.2,A/2);
Prawa.Ustaw(C/1.2,A/2);

SWektor<double,3> Lewy((-1*A),(-B/2),0);
PozycjaLewa = Lewy +Srodek;
Lewa.ustaw_pozycje(Lewy);

SWektor<double,3> Prawy((-1*A),(B/2),0);
PozycjaPrawa = Prawy + Srodek;
Prawa.ustaw_pozycje(Prawy);

}

void Dron::ustaw_api(std::shared_ptr<drawNS::Draw3DAPI> API){
Prostopadloscian::ustaw_api(API);
Lewa.ustaw_api(API);
Prawa.ustaw_api(API);
}

void Dron::Rysuj() {
Prostopadloscian::Rysuj();
Lewa.Rysuj();
Prawa.Rysuj();

}

void Dron::Obrot(double stopnie) {
MacierzOb Obrot(stopnie);
Orientacja = Orientacja * Obrot;
Lewa.ObrotDR(PozycjaLewa,Obrot,Orientacja);
Prawa.ObrotDR(PozycjaPrawa,Obrot,Orientacja);

}

void Dron::Przesun(double odleglosc, double stopnie) {
SWektor<double,3> przesuniecie(odleglosc*cos(stopnie*M_PI/180),0,odleglosc*sin(stopnie*M_PI/180));

(*this).Orient_wektor(przesuniecie);
Srodek = Srodek + przesuniecie;

Lewa.Przesun(odleglosc,stopnie);
Prawa.Przesun(odleglosc,stopnie);
}


void Dron::ObrotA(double kat) {
while (kat){
    if (kat >= 1) {
      kat = kat - 1;
      Obrot(1);
      Rysuj();
      Lewa.Obracaj();
      usleep(10000);
    }
    else if (kat <= -1){
      Obrot(-1);
      Prawa.Obracaj();
      kat = kat + 1;
      Rysuj();
      usleep(10000);
    }
    else {
      Obrot(kat);
      kat = 0;
      Rysuj();
      usleep(10000);
    }
  }
}

void Dron::Plyn(double odleglosc, double stopnie){


if (odleglosc > 0){
    for(int i=0; i <= odleglosc; i++){
    Prawa.Obracaj();
    Lewa.Obracaj();


    (*this).Przesun(1,stopnie);
    Rysuj();
    usleep(10000);
    }
}

if (odleglosc < 0){
    for(int i=0; i >= odleglosc; i--){
    Prawa.Obracaj();
    Lewa.Obracaj();
    (*this).Przesun(-1,stopnie);

    Rysuj();
    usleep(10000);
}}

}

























