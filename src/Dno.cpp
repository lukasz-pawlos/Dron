#include "Dno.hh"

Dno::Dno(double wymiar) {
bok = wymiar;

}


void Dno::Rysuj(){
  int ID=0;
    ID = api ->draw_surface(vector<vector<Point3D> > {{
        drawNS::Point3D(-100,-100,-100),drawNS::Point3D(-100,0,-100),drawNS::Point3D(-100,100,-100)
    },{
    drawNS::Point3D(0,-100,-100),drawNS::Point3D(0,0,-100),drawNS::Point3D(0,100,-100)
    },{
    drawNS::Point3D(100,-100,-100),drawNS::Point3D(100,0,-100),drawNS::Point3D(100,100,-100)
    }}, "yellow");

}
