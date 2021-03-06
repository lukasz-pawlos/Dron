#include "MacierzOb.hh"


using std::cout;
using std::endl;

MacierzOb::MacierzOb(const SMacierz<double,3> & M) : SMacierz <double,3> (M){

double epsilon = 0.0000000001;

if(abs(tab[0] * tab[1]) >epsilon){
    cout << "Macierz nie jest ortygonalna" << endl;
    exit(1);
}
if(abs(tab[1] * tab[2]) >epsilon){
    cout << "Macierz nie jest ortygonalna" << endl;
    exit(1);
}
if(abs(tab[0] * tab[2]) >epsilon){
    cout << "Macierz nie jest ortygonalna" << endl;
    exit(1);
}
if(abs((*this).det() - 1) > epsilon){
    cout << "Macierz nie jest ortygonalna" << endl;
    exit(1);
}

}

MacierzOb::MacierzOb(){
    SWektor<double,3> ZERO(1,0,0);
    SWektor<double,3> JEDEN(0,1,0);
    SWektor<double,3> DWA(0,0,1);

        (*this)[0] = ZERO;
        (*this)[1] = JEDEN;
        (*this)[2] = DWA;

}


MacierzOb::MacierzOb(double stopnie){

    tab[0][0] = cos(stopnie * M_PI/180);
    tab[0][1] = -sin(stopnie * M_PI/180);
    tab[0][2] = 0;
    tab[1][0] = sin(stopnie * M_PI/180);
    tab[1][1] = cos(stopnie * M_PI/180);
    tab[1][2] = 0;
    tab[2][0] = 0;
    tab[2][1] = 0;
    tab[2][2] = 1;
}


MacierzOb MacierzOb::OSX(double stopnie)
{

    tab[0][0] = 1;
    tab[0][1] = 0;
    tab[0][2] = 0;
    tab[1][0] = 0;
    tab[1][1] = cos(stopnie * M_PI/180);
    tab[1][2] = -sin(stopnie * M_PI/180);
    tab[2][0] = 0;
    tab[2][1] = sin(stopnie * M_PI/180);
    tab[2][2] = cos(stopnie * M_PI/180);

}
