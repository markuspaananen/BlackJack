#include "blackjack.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <random>


/*
   Memos - Poista valmiista

*/

void blackjack()
{
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|*********************  Blackjack  **********************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|-- Rules --                                             |*\n";
    std::cout << "*|    1. Dealer always wins                               |*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|-- Aloita peli --  Press 1                              |*\n";
    std::cout << "*|********************************************************|*\n";
}




void voitto()
{
    std::cout << "Voitit pelin\n";
}
void havio()
{
    std::cout << "Havisit pelin\n";
}
int annakortti()
{
    //Pakka. Sekoita ennen käyttöä

    std::random_device dev;
        std::mt19937 rng(dev());
        std::uniform_int_distribution<std::mt19937::result_type> num(1,10);

        return num(rng);
}
