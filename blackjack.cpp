#include <iostream>
#include <random>

#include "blackjack.h"
#include "Pelaaja.h"
#include "Jakaja.h"


void Blackjack::paamenu()
{
    int exit_game = 1;

        do
        {
            Blackjack::Title();

            Blackjack kasino;
            kasino.playGame();
            std::cout << "haluatko pelata uudestaan? (1 = Kylla, 2 = Ei)\n";

            std::cin >> exit_game;
        }while(exit_game == 1);

}

void Blackjack::Title()
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

void Blackjack::voitto()
{
    std::cout << "*|*********************  Voitit pelin  **********************|*\n";


}
void Blackjack::havio()
{
    std::cout << "-|---------------------  Havisit pelin  ----------------------|-\n";

}
Blackjack::Blackjack()
{
    //Vaatii tämän että toimii en tiedä miksi.
    //Se toimii, olkoon niin sitten.
}

void Blackjack::playGame()
{


    peli = true;
    Blackjack::Title();
    int tunnus;
    std::cout << "Aseta tunnusnumero?";
    std::cin >> tunnus;

    Pelaaja a1 = Pelaaja(tunnus);
    Jakaja a2;

    int pk1 = Pelaaja::annakortti();
    int pk2 = Pelaaja::annakortti();
    int jk1 = Jakaja::annakortti(); // Käytetty perintää ehkä turhaan mutta käytetty kuitenkin.
                                     // En oikein tällä taitotasolla tiennyt miten muuten sitä hyödyntäisin.

    a1.setPisteet(pk1+pk2);


    std::cout << "Tunnuslukusi on " << a1.getTunniste() << "\n";


    std::cout << "Jakajan korteista toinen on katketty."
                 "\njakajan esilla olevan kortti on " << jk1 << "\n\n";

    jk1 = jk1 + Pelaaja::annakortti();
    a2.setPisteet(jk1);

    std::cout << "Jakaja antoi sinulle kortit joiden pistearvo on " << pk1 << " ja " << pk2 << "\n";
    std::cout << "Sinulla on " << pk1 + pk2 << " pistetta.\n";

    pk1 = pk1 + pk2;





    std::cout << "Haluatko nostaa kortin? Paina Y/n\n";
       std::string x = "N";
       std::cin >> x;

       while (x == "Y" || x == "y")
       {
           int pk2 = Pelaaja::annakortti();
           std::cout << "Nostit kortin jonka arvo on " << pk2 << "\n";
           pk1 = pk1 + pk2;
           std::cout << "Korttiesi arvo on nyt " << pk1 << "\n";

           std::cout << "Haluatko nostaa viela kortin? Y/n\n";
           std::cin >> x;

           if (pk1 > 22)
           {

               break;
           }
       }

       if (pk1 > 21)
       {
           Blackjack::havio();
           peli = false;
           return;
       }

       if (pk1 == 21)
       {
           voitto();
           peli = false;
           return;
       }
       std::cout << "Jakaja paljasti korttinsa\n";
       std::cout << "Jakajalla on " << jk1 << " pistetta\n";


       while (jk1 <= 16)
       {
           //std::cout << "Jakajan pistemaara on alle 17\n";
           std::cout << "Jakaja nosti kortin\n";
           jk1 += Jakaja::annakortti();
           std::cout << "Jakajan korttien arvo on nyt " << jk1 << "\n";

       }
       if (jk1 > 21)
       {
           voitto();
           peli = false;
           return;
       }
       if (jk1 == 21)
       {
           havio();
           peli = false;
           return;
       }
       if ( jk1 < pk1)
       {
           std::cout << "Jakajan korttien arvo on " << jk1 << "\n";
           std::cout << "Pelaajan korttien arvo on " << pk1 << "\n";
           voitto();
           return;
       }
       else
       {
           std::cout << "Jakajan korttien arvo on " << jk1 << "\n";
           std::cout << "Pelaajan korttien arvo on " << pk1 << "\n";
           havio();
           return;
       }
}






        //std::cout << "Pelaaja Pisteet:" << a1.getPisteet() << " tunniste:" << a1.getTunniste() << std::endl;
        //std::cout << "Jakaja Pisteet:" << a2.getPisteet() << std::endl;







