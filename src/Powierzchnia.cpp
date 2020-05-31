#include "Powierzchnia.hh"


Powierzchnia::Powierzchnia() {}

Powierzchnia::Powierzchnia(double glebokosc, double wymiar) {
SWektor<double,3> W (0,0,glebokosc);
Srodek = W;
bok = wymiar;
updown = glebokosc;
}

void Powierzchnia::Wspolrzedne(SWektor<double,3> *wsp) const {


SWektor<double,3> przesX(bok/2,0,updown);
SWektor<double,3> przesY(0,bok/2,updown);

wsp[0] = Srodek - przesX - przesY;
wsp[1] = Srodek - przesX;
wsp[2] = Srodek - przesX + przesY;
wsp[3] = Srodek + przesX + przesY;
wsp[4] = Srodek + przesX;
wsp[5] = Srodek + przesX - przesY;

}


void Powierzchnia::Rysuj() {
SWektor<double,3> tab[4];
(*this).Wspolrzedne(tab);

if (ID != -1)
api->erase_shape(ID);



ID = api ->draw_surface(vector<vector<Point3D> > {{
    /*drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]),drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]),drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2])
    },{
    drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]),drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]),drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])*/
        drawNS::Point3D(-100,-100,-100),drawNS::Point3D(-100,0,-100),drawNS::Point3D(-100,100,-100)
    },{
    drawNS::Point3D(0,100,-100),drawNS::Point3D(0,0,-100),drawNS::Point3D(0,-100,-100)
    },{
    drawNS::Point3D(100,100,-100),drawNS::Point3D(100,0,-100),drawNS::Point3D(100,-100,-100)
    }}, "red");





}
