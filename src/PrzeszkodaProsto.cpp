#include "PrzeszkodaProsto.hh"

PrzeszkodaProsto::PrzeszkodaProsto(double Abok, double Bbok, double Cbok){

if (Abok < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

if (Bbok < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

if (Cbok < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

A = Abok;
B = Bbok;
C = Cbok;
}


bool PrzeszkodaProsto::Kolizja(std::shared_ptr<InterfejsDrona> Inter) const {

std::shared_ptr<Dron> plywak1 = std::static_pointer_cast<Dron> (Inter);
double promien = plywak1->WezPromien();
SWektor<double,3> SrodekD = plywak1->daj_srodek();

if(SrodekD[0] > Srodek[0] - (A/2) - promien)
    if(SrodekD[0] > Srodek[0] + (A/2) + promien)
        if(SrodekD[1] > Srodek[1] - (B/2) - promien)
            if(SrodekD[1] > Srodek[1] + (B/2) + promien)
                if(SrodekD[2] > Srodek[2] - (C/2) - promien)
                    if(SrodekD[2] > Srodek[2] + (C/2) + promien)
                    return true;

return false;


}
