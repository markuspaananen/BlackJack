#include "blackjack.h"
#include <iostream>


int main()
{


    bool peli = true;
    int valinta;
    std::string varmistus;

    blackjack();


    do
    { std::cout<<"Enter your choice(1-2):";
    std::cin>>valinta;
    switch (valinta)
    {
    case 1:
        {
        std::cout << "Aloitit pelin\n";

        while (peli == true)
        {

        int pelaaja_total = 0;
        int jakajan_total = 0;

        int jakajan_card1 = annakortti();
        int jakajan_card2 = annakortti();
        jakajan_total = jakajan_card1 + jakajan_card2;
        std::cout << "Jakajan korteista toinen on katketty.\njakajan esilla olevan kortti on " << jakajan_card1 << "\n\n";


        int card1 = annakortti();
        int card2 = annakortti();

        pelaaja_total = card1 + card2;
        std::cout << "Jakaja antoi sinulle kortit joiden pistearvo on " << card1 << " ja " << card2 << "\n";
        std::cout << "Sinulla on " << pelaaja_total << " pistetta.\n";

        std::cout << "Haluatko nostaa kortin? Paina Y/n\n";
        std::string x = "N";
        std::cin >> x;

        while (x == "Y" || x == "y")
        {
            int card3 = annakortti();
            std::cout << "Nostit kortin jonka arvo on " << card3 << "\n";
            pelaaja_total = pelaaja_total + card3;
            std::cout << "Korttiesi arvo on nyt " << pelaaja_total << "\n";

            std::cout << "Haluatko nostaa viela kortin? Y/n\n";
            std::cin >> x;

            if (pelaaja_total > 22)
            {
                havio();
                break;
            }
        }
        if (pelaaja_total > 21)
        {
            havio();
            peli = false;
            break;
        }
        if (pelaaja_total == 21)
        {
            voitto();
            peli = false;
            break;
        }
        std::cout << "Jakaja paljasti korttinsa\n";
        std::cout << "Jakajalla on " << jakajan_total << " pistetta\n";


        while (jakajan_total <= 16)
        {
            std::cout << "Jakajan pistemaara on alle 17\n";
            std::cout << "Jakaja nosti kortin\n";
            int card = annakortti();
            std::cout << "Jakaja nosti kortin jonka arvo on " << card << "\n";
            jakajan_total = jakajan_total + card;
            std::cout << "Jakajan korttien arvo on nyt " << jakajan_total << "\n";

        }
        if (jakajan_total > 21)
        {
            voitto();
            peli = false;
            break;
        }
        if (jakajan_total == 21)
        {
            havio();
            peli = false;
            break;
        }
        if ( jakajan_total < pelaaja_total)
        {
            std::cout << "Jakajan korttien arvo on " << jakajan_total << "\n";
            std::cout << "Pelaajan korttien arvo on " << pelaaja_total << "\n";
            voitto();
            break;
        }
        else
        {
            std::cout << "Jakajan korttien arvo on " << jakajan_total << "\n";
            std::cout << "Pelaajan korttien arvo on " << pelaaja_total << "\n";
            havio();
            break;
        }

        }

    }


        break;
    case 2:


        break;
    default: std::cout<<"invalid"; break;
    }

    std::cout<<"Palaa paavalikkoon painamalla Y\n";
    std::cin>>varmistus;
    } while (varmistus == "y" || varmistus == "Y");
    return 0;
    }




