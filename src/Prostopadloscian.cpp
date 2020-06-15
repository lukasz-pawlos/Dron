#include "Prostopadloscian.hh"

Prostopadloscian::Prostopadloscian() {}

Prostopadloscian::Prostopadloscian(double bok_A, double bok_B, double bok_C){

if (bok_A < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

if (bok_B < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

if (bok_C < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

A = bok_A;
B = bok_B;
C = bok_C;




}

void Prostopadloscian::Orient_wektor(SWektor<double,3> &W)const {
W= Orientacja * W;
}

void Prostopadloscian::Wspolrzedne(SWektor<double,3> *wsp)const {


SWektor<double,3> przesX(A,0,0);
SWektor<double,3> przesY(0,B,0);
SWektor<double,3> przesZ(0,0,C);

(*this).Orient_wektor(przesX);
(*this).Orient_wektor(przesY);
(*this).Orient_wektor(przesZ);


wsp[0] = Srodek + przesX + przesY + przesZ;
wsp[1] = Srodek + przesX - przesY + przesZ;
wsp[2] = Srodek - przesX - przesY + przesZ;
wsp[3] = Srodek - przesX + przesY + przesZ;
wsp[4] = Srodek + przesX + przesY - przesZ;
wsp[5] = Srodek + przesX - przesY - przesZ;
wsp[6] = Srodek - przesX - przesY - przesZ;
wsp[7] = Srodek - przesX + przesY - przesZ;

}

void Prostopadloscian::ustaw_pozycje(const SWektor<double,3> &Wektor) {
Srodek = Wektor;
}

void Prostopadloscian::ustaw_orientacje(const MacierzOb &Macierz) {
Orientacja = Macierz;
}

void Prostopadloscian::ustaw_srodek(double X, double Y, double Z){
Srodek[0] = X;
Srodek[1] = Y;
Srodek[2] = Z;
}


void Prostopadloscian::Rysuj() {
SWektor<double,3> tab[8];
(*this).Wspolrzedne(tab);
if (ID != -1)
api->erase_shape(ID);



ID = api ->draw_polyhedron(vector<vector<Point3D> > {{
    drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]),drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]),drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]),drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
    },{
    drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]),drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2]),drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]),drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2])
    }
    }, "red");


}
















