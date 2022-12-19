#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <random>

#include "Pelaaja.h"
//Määritellään staattinen muuttuja
//int Pelaaja::tehdytAutot = 0;


Pelaaja::Pelaaja()
{
    srand( (unsigned)time(NULL) );
    tunniste  = rand();
    //tehdytAutot++;
}

Pelaaja::Pelaaja(long tunniste)
{
    this->tunniste  = tunniste;
    //tehdytAutot++;
}

void Pelaaja::setPisteet(int n)
{
    this->pisteet = n;
}
void Pelaaja::setTunniste(long t)
{
    this->tunniste = t;
}

int Pelaaja::getPisteet()
{
    return pisteet;
}

long Pelaaja::getTunniste()
{
    return  tunniste;
}

int Pelaaja::annakortti()
{
    //Pakka. Sekoita ennen käyttöä

    std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> num(1,12);

        int pakka[14];
        pakka[0] = 1;
        pakka[1] = 2;
        pakka[2] = 3;
        pakka[3] = 4;
        pakka[4] = 5;
        pakka[5] = 6;
        pakka[6] = 7;
        pakka[7] = 8;
        pakka[8] = 9;
        pakka[9] = 10; //10
        pakka[10] = 10; // jätkä
        pakka[11] = 10; // Kuningatar
        pakka[12] = 10; // Kuningas
           //ässä puuttuu

        return pakka[num(rng)];
}
