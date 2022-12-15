#ifndef BLACKJACK_H
#define BLACKJACK_H


#include <iostream>
#include <string>
void blackjack();
void voitto();
void havio();
int annakortti();
int voitot();

class Blackjack
{
public:
    Blackjack();
     Blackjack(int tunniste);

    void playGame();
    int voitot;
private:
    int tunniste;
    bool peli;
    int pelaaja_total;
    int jakajan_total;

};




class Pelaaja: public Blackjack
{
public:
    std::string nimi();
    int pisteet();

};

#endif // BLACKJACK_H
