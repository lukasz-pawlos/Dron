#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"
#include "GraniastoslupSzes.hh"
#include "Sruba.hh"
#include "Powierzchnia.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {

  Dron Plywak(15,20,10);
  double kat;
  double odleglosc;

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"

  Plywak.ustaw_api(api);
    Plywak.Rysuj();







    int ID=0;
    ID = api ->draw_surface(vector<vector<Point3D> > {{
    /*drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]),drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]),drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2])
    },{
    drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]),drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]),drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])*/
        drawNS::Point3D(-100,-100,-100),drawNS::Point3D(-100,0,-100),drawNS::Point3D(-100,100,-100)
    },{
    drawNS::Point3D(0,-100,-100),drawNS::Point3D(0,0,-100),drawNS::Point3D(0,100,-100)
    },{
    drawNS::Point3D(100,-100,-100),drawNS::Point3D(100,0,-100),drawNS::Point3D(100,100,-100)
    }}, "yellow");


    ID = api ->draw_surface(vector<vector<Point3D> > {{
    /*drawNS::Point3D(tab[0][0],tab[0][1],tab[0][2]),drawNS::Point3D(tab[1][0],tab[1][1],tab[1][2]),drawNS::Point3D(tab[2][0],tab[2][1],tab[2][2])
    },{
    drawNS::Point3D(tab[3][0],tab[3][1],tab[3][2]),drawNS::Point3D(tab[4][0],tab[4][1],tab[4][2]),drawNS::Point3D(tab[5][0],tab[5][1],tab[5][2])*/
        drawNS::Point3D(-100,-100,100),drawNS::Point3D(-100,0,100),drawNS::Point3D(-100,100,100)
    },{
    drawNS::Point3D(0,-100,100),drawNS::Point3D(0,0,100),drawNS::Point3D(0,100,100)
    },{
    drawNS::Point3D(100,-100,100),drawNS::Point3D(100,0,100),drawNS::Point3D(100,100,100)
    }}, "blue");












    cout << "Obsługa drona"<<endl;
    cout << "r - ruch na wprost"<<endl;
    cout << "o - obrot"<<endl;
    cout << "m - menu"<<endl;
    cout << "k - koniec pracy"<<endl;


char wybor;
while(wybor != 'k')
{
    cin >> wybor;

    switch (wybor)
    {

    case 'r':
    cout << "Podaj odleglosc: ";
    cin >> odleglosc;
    cout << "Podaj kat: ";
    cin >> kat;

    Plywak.Plyn(odleglosc,kat);

    break;

    case 'o':
    cout << "Podaj kat obrotu: ";
    cin >> kat;

        Plywak.ObrotA(kat);

    break;

    case 'm':
    cout << "Obsługa drona"<<endl;
    cout << "r - ruch na wprost"<<endl;
    cout << "o - obrot"<<endl;
    cout << "m - menu"<<endl;
    cout << "k - koniec pracy"<<endl;
    break;

    default:
    cout << "BRAK TAKIEJ OBCJI"<<endl;
    cout << "m - menu"<<endl;
    break;
    }

}
}
