#include "GraniastoslupSzes.hh"
#include <cmath>

GraniastoslupSzes::GraniastoslupSzes() {}

GraniastoslupSzes::GraniastoslupSzes(double Abok, double Hbok) {

if (Abok < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

if (Hbok < 0){
    cout << "Bok nie moze byc liczba ujemna" << endl;
    exit(1);
}

A = Abok;
B = Hbok;

}

void GraniastoslupSzes::Orient_wektor(SWektor<double,3> &Wek)const {

Wek = Orientacja * Wek;
}


void GraniastoslupSzes::Wspolrzedne(SWektor<double,3>* wsp)const {

SWektor<double,3> przesX(H/2,0,0);
SWektor<double,3> przesY(0,A,0);
SWektor<double,3> przesY2(0,A/2,C);
SWektor<double,3> przesZ(0,0,A*sqrt(3)/2);

(*this).Orient_wektor(przesX);
(*this).Orient_wektor(przesY);
(*this).Orient_wektor(przesY2);
(*this).Orient_wektor(przesZ);

wsp[0] = Srodek + przesX + przesY;
wsp[1] = Srodek + przesX + przesY2 + przesZ;
wsp[2] = Srodek + przesX - przesY2 + przesZ;
wsp[3] = Srodek + przesX - przesY;
wsp[4] = Srodek + przesX - przesY2 - przesZ;
wsp[5] = Srodek + przesX + przesY2 - przesZ;

wsp[6] = Srodek - przesX + przesY;
wsp[7] = Srodek - przesX + przesY2 + przesZ;
wsp[8] = Srodek - przesX - przesY2 + przesZ;
wsp[9] = Srodek - przesX - przesY;
wsp[10] = Srodek - przesX - przesY2 - przesZ;
wsp[11] = Srodek - przesX + przesY2 - przesZ;
}


unsigned int GraniastoslupSzes::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api) {

SWektor<double,3> tab[12];
(*this).Wspolrzedne(tab);

unsigned int tmp = api ->draw_polyhedron(vector<vector<Point3D> > {{
    drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]),drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]),drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]),
    drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]),drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]),drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])
    },{
    drawNS::Point3D(tab[6][0],tab[6][1],tab[6][2]),drawNS::Point3D(tab[7][0],tab[7][1],tab[7][2]),drawNS::Point3D(tab[8][0],tab[8][1],tab[8][2]),
    drawNS::Point3D(tab[9][0],tab[9][1],tab[9][2]),drawNS::Point3D(tab[10][0],tab[10][1],tab[10][2]),drawNS::Point3D(tab[11][0],tab[11][1],tab[11][2]),
    }
    }, "red");

return tmp;



}














