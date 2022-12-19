#ifndef BLACKJACK_H
#define BLACKJACK_H

class Blackjack
{
public:
    Blackjack();
    void playGame();


    //Staattisen muuttujat:
public:
    static void paamenu();
    static void Title();
    static void voitto();
    static void havio();
private:
    bool peli;
    int pk1;
    int pk2;
    int jk1;
    int jk2;
    int tunnus;
};



#endif // BLACKJACK_H
