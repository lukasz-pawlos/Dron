#include "Powierzchnia.hh"


Powierzchnia::Powierzchnia() {};

Powierzchnia::Powierzchnia(double glebokosc, double wymiar) {
SWektor<double,3> W (0,0,glebokosc);
Srodek = W;
bok = wymiar;
updown = glebokosc;
}

void Powierzchnia::Wspolrzedne(SWektor<double,3> *wsp) const {


SWektor<double,3> przesX(bok/2,0,updown);
SWektor<double,3> przesY(0,bok/2,updown);

wsp[0] = Srodek + przesX + przesY;
wsp[1] = Srodek + przesX - przesY;
wsp[2] = Srodek - przesX - przesY;
wsp[3] = Srodek - przesX + przesY;

}


unsigned int Powierzchnia::Rysuj(std::shared_ptr<drawNS::Draw3DAPI> api)const {
SWektor<double,3> tab[4];
(*this).Wspolrzedne(tab);



unsigned int tmp = api ->draw_polyhedron(vector<vector<Point3D> > {{
    drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]),drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]),drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2]),drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2])
    }
    }, "black");

return tmp;




}
