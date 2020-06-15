#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Prostopadloscian.hh"
#include "InterfejsDrona.hh"
#include "Dron.hh"
#include "GraniastoslupSzes.hh"
#include "Sruba.hh"
#include "Powierzchnia.hh"
#include "Tafla.hh"
#include "Dno.hh"
#include "Przeszkoda.hh"
#include "PrzeszkodaProsto.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;
using std::cin;

int main() {

  double kat;
  double odleglosc;
  std::shared_ptr<Dron> Robot = NULL;
  int numer = 0;

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-100,100,-100,100,-100,100,0));
  std::shared_ptr<Dron> plywak1(new Dron(15,20,10));
  std::shared_ptr<Dron> plywak2(new Dron(15,20,10));
  std::shared_ptr<Dron> plywak3(new Dron(15,20,10));
  std::shared_ptr<PrzeszkodaProsto> Przesz1(new PrzeszkodaProsto(15,15,25));
  std::shared_ptr<PrzeszkodaProsto> Przesz2(new PrzeszkodaProsto(30,35,20));
  std::shared_ptr<PrzeszkodaProsto> Przesz3(new PrzeszkodaProsto(20,10,5));
  std::vector<std::shared_ptr<InterfejsDrona> > kolekcja_dronow;
  std::vector<std::shared_ptr<Przeszkoda> > kolekcja_przeszkod;


  kolekcja_przeszkod.push_back(plywak1);
  kolekcja_przeszkod.push_back(plywak2);
  kolekcja_przeszkod.push_back(plywak3);
  kolekcja_przeszkod.push_back(Przesz1);
  kolekcja_przeszkod.push_back(Przesz2);
  kolekcja_przeszkod.push_back(Przesz3);
  kolekcja_dronow.push_back(plywak1);
  kolekcja_dronow.push_back(plywak2);
  kolekcja_dronow.push_back(plywak3);


  plywak1->ustaw_api(api);
  plywak2->ustaw_api(api);
  plywak3->ustaw_api(api);
  Przesz1->ustaw_api(api);
  Przesz2->ustaw_api(api);
  Przesz3->ustaw_api(api);


  plywak2->Przesun(-50,30,90);
  plywak3->Przesun(10,-60,-50);
  Przesz1->ustaw_srodek(70,40,-40);
  Przesz2->ustaw_srodek(-60,-20,-20);
  Przesz3->ustaw_srodek(-25,70,-25);

  plywak1->ustaw_kolekcje_przeszkod(kolekcja_przeszkod);
  plywak2->ustaw_kolekcje_przeszkod(kolekcja_przeszkod);
  plywak3->ustaw_kolekcje_przeszkod(kolekcja_przeszkod);


    int ID=0;
    ID = api ->draw_surface(vector<vector<Point3D> > {{
        drawNS::Point3D(-100,-100,-100),drawNS::Point3D(-100,0,-100),drawNS::Point3D(-100,100,-100)
    },{
    drawNS::Point3D(0,-100,-100),drawNS::Point3D(0,0,-100),drawNS::Point3D(0,100,-100)
    },{
    drawNS::Point3D(100,-100,-100),drawNS::Point3D(100,0,-100),drawNS::Point3D(100,100,-100)
    }}, "yellow");


    ID = api ->draw_surface(vector<vector<Point3D> > {{
        drawNS::Point3D(-100,-100,100),drawNS::Point3D(-100,0,100),drawNS::Point3D(-100,100,100)
    },{
    drawNS::Point3D(0,-100,100),drawNS::Point3D(0,0,100),drawNS::Point3D(0,100,100)
    },{
    drawNS::Point3D(100,-100,100),drawNS::Point3D(100,0,100),drawNS::Point3D(100,100,100)
    }}, "blue");


    Przesz1->Rysuj();
    Przesz2->Rysuj();
    Przesz3->Rysuj();
    plywak1->Rysuj();
    plywak2->Rysuj();
    plywak3->Rysuj();


    cout << "Wybierz numer drona ( 1 lub 2 lub 3 ): ";
    while(numer >3 || numer <1) {
            cin >> numer;
    if (numer ==1)
        Robot =std::static_pointer_cast<Dron> (kolekcja_dronow[0]);
    if (numer ==2)
        Robot =std::static_pointer_cast<Dron> (kolekcja_dronow[1]);
    if (numer ==3)
        Robot =std::static_pointer_cast<Dron> (kolekcja_dronow[2]);
        else{
        cout <<"ZLY NUMER DRONA :-(" << endl << endl;
        cout <<"Podaj numer drona ( 1 lub 2 lub 3 ): ";
        }}






    cout << "Obsługa drona"<<endl;
    cout << "r - ruch na wprost"<<endl;
    cout << "o - obrot"<<endl;
    cout << "m - menu"<<endl;
    cout << "k - koniec pracy"<<endl;
    cout << "z - zmiana drona"<<endl;


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

    Robot->Plyn(odleglosc,kat);

    break;

    case 'o':
    cout << "Podaj kat obrotu: ";
    cin >> kat;

        Robot->ObrotA(kat);

    break;

    case 'm':
    cout << "Obsługa drona"<<endl;
    cout << "r - ruch na wprost"<<endl;
    cout << "o - obrot"<<endl;
    cout << "m - menu"<<endl;
    cout << "k - koniec pracy"<<endl;
    cout << "z - zmiana drona"<<endl;
    break;

    case 'z':
    numer = 0;
    cout << "Wybierz numer drona ( 1 lub 2 lub 3 ): ";
    while(numer >3 || numer <1) {
            cin >> numer;
    if (numer ==1)
        Robot =std::static_pointer_cast<Dron> (kolekcja_dronow[0]);
    if (numer ==2)
        Robot =std::static_pointer_cast<Dron> (kolekcja_dronow[1]);
    if (numer ==3)
        Robot =std::static_pointer_cast<Dron> (kolekcja_dronow[2]);
        else{
        cout <<"ZLY NUMER DRONA :-(" << endl << endl;
        cout <<"Podaj numer drona ( 1 lub 2 lub 3 ): ";
        }}
    break;

    case 'k':
    cout << "Koniec pracy"<<endl;
    break;



    default:
    cout << "BRAK TAKIEJ OBCJI"<<endl;
    cout << "m - menu"<<endl;
    break;
    }

}
}


