#include "Tafla.hh"

Tafla::Tafla(double wymiar) {
bok = wymiar;


}

void Tafla::Rysuj()
{
    int ID=0;
    ID = api ->draw_surface(vector<vector<Point3D> > {{
        drawNS::Point3D(-100,-100,100),drawNS::Point3D(-100,0,100),drawNS::Point3D(-100,100,100)
    },{
    drawNS::Point3D(0,-100,100),drawNS::Point3D(0,0,100),drawNS::Point3D(0,100,100)
    },{
    drawNS::Point3D(100,-100,100),drawNS::Point3D(100,0,100),drawNS::Point3D(100,100,100)
    }}, "blue");
}
