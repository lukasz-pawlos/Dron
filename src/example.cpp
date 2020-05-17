#include <iostream>
#include "Dr3D_gnuplot_api.hh"
#include "SWektor.hh"
#include "Macierz.hh"
#include "MacierzOb.hh"
#include "Prostopadloscian.hh"
#include "Dron.hh"

using std::vector;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;
using std::cout;
using std::endl;

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {

  Dron Plywak(2,4,2);
  double kat;
  double odleglosc;

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-10,10,-10,10,-10,10,1000)); //włacza gnuplota, pojawia się scena [-5,5] x [-5,5] x [-5,5] odświeżana co 1000 ms
  //drawNS::Draw3DAPI * api = new APIGnuPlot3D(-5,5,-5,5,-5,5,1000); //alternatywnie zwykły wskaźnik
  api->change_ref_time_ms(0); //odświeżanie sceny zmienione na opcję "z każdym pojawieniem się lub zniknięciem kształtu"

  int a = Plywak.Rysuj(api);



}
