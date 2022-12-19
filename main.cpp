#include <iostream>

#include "blackjack.h"


int main()
{

    int yourchoice;
    std::string confirm;
    do
    {
        system("cls");
        std::cout << "===============================================\n";
        std::cout << "\tMita haluaisit pelata\n";
        std::cout << "===============================================\n";
        std::cout << "\npaina 1. Pelaa Blackjack pelia.";
        std::cout << "\npaina 2. Poistu.";
        std::cout << "\npaina 3. Selvita arvoitus.";

        std::cout<<"\nEnter your choice(1-3):";
        std::cin>>yourchoice;

    switch (yourchoice)
    {
    case 1: Blackjack::paamenu(); break;
    case 2: return 0; break;
    case 3: std::cout<<"Cake is a lie.\n"; break;

    default: std::cout<<"invalid"; break;
    }
    std::cout<<"paina Y/y palataksesi paavalikkoon:";
    std::cin>>confirm;
    } while (confirm == "y" || confirm == "Y");
    return 0;


}


