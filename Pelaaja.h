#ifndef Pelaaja_H
#define Pelaaja_H
#include <string>

class Pelaaja
{
public:
    Pelaaja();
     Pelaaja(long tunniste);

    void setPisteet(int n);
    void setTunniste(long t);

    int getPisteet();
    long getTunniste();


    //Staattisen muuttujat:
public:
    //static int tehdytAutot;
    static int annakortti();
private:
    int pisteet;
    long tunniste;
    //int voitot();

};


#endif // Pelaaja_H
