#include "blackjack.h"
#include <iostream>

//int pakka[13][3];

//int randomcard = rand() % 51 + 1;

int main()
{
    int exit_game = 1;

    do
    {
        blackjack();
        Blackjack kasino;
        kasino.playGame();
        std::cout << "haluatko pelata uudestaan? (1 = Kylla, 2 = Ei)\n";

        std::cin >> exit_game;
    }while(exit_game == 1);

    std::cout << "Kiitos kun pelasit\n";
    system("pause");
    return 0;

}





