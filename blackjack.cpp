#include "blackjack.h"
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <stdlib.h>
#include <random>


/*
   Memos - Poista valmiista

*/
Blackjack::Blackjack()
{
    //std::cout << "haluamasi pelinumero?: " << "\n";
    //std::cin >>  tunniste;


}
/*
Blackjack::Blackjack(int tunniste)
{
    //this->tunniste  = tunniste;
}
*/

void Blackjack::playGame()
{
    peli = true;
    pelaaja_total = 0;
    jakajan_total = 0;

     Blackjack pel1 = Blackjack();


    std::cout << "Aloitit pelin\n";

    while (peli == true)
    {

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
        //std::cout << "Jakajan pistemaara on alle 17\n";
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

void blackjack()
{
    system("cls");
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|*********************  Blackjack  **********************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|********************************************************|*\n";
    std::cout << "*|-- Rules --                                             |*\n";
    std::cout << "*|    1. 21 pistetta ensin saanut voittaa                 |*\n";
    std::cout << "*|    2. ensimmainen yli 21 pistetta haviaa               |*\n";
    std::cout << "*|    3. lopuksi eniten pisteita saanut voittaa           |*\n";
    std::cout << "*|       (Kunhan pistemaara ei ole yli 21)                |*\n";
    std::cout << "*|********************************************************|*\n";
}




void voitto()
{
    std::cout << "*|*********************  Voitit pelin  **********************|*\n";

}
void havio()
{
    std::cout << "-|---------------------  Havisit pelin  ----------------------|-\n";
}
int annakortti()
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
