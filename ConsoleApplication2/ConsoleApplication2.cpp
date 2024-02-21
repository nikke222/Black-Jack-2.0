#include <iostream>
#include <cstdlib>

//C++ Kev‰t 24 projekti
//Niklas Kentala ATS21K

// Luokka "Kortti"
class Kortti 
{
public:
    int arvo;
    // Arpoo kortin arvon
    Kortti() {
        arvo = rand() % 10 + 1;
    }
};

// Luokka "Pelaaja"
class Pelaaja 
{
public:
    int pisteet;
    // Asettaa pisteet nollaksi
    Pelaaja() 
    {
        pisteet = 0;
    }
    // Metodi joka ottaa uuden kortin ja lis‰‰ sen arvon pelaajan pisteisiin
    void otaKortti() 
    {
        Kortti kortti;
        pisteet += kortti.arvo;
    }
};

// Luokka "Jakaja"
class Jakaja 
{
public:
    int pisteet;
    // Asettaa pisteet nollaksi
    Jakaja() 
    {
        pisteet = 0;
    }
    // Metodi joka ottaa uuden kortin ja lis‰‰ sen jakaajan pisteisiin
    void otaKortti() 
    {
        Kortti kortti;
        pisteet += kortti.arvo;
    }
};

int main()
{
    // Satunnaislukugeneraattori
    srand(time(0));
    // Pelaajan ja jakajan oliot
    Pelaaja pelaaja;
    Jakaja jakaja;

    // Pelaajalle kaksi korttia ja jakajalle yksi
    pelaaja.otaKortti();
    pelaaja.otaKortti();
    jakaja.otaKortti();

    std::cout << "Sinulla on " << pelaaja.pisteet << " pistett‰ ja jakajalla on " << jakaja.pisteet << " pistett‰\n";

    // Pelaajan vuoro
    while (pelaaja.pisteet < 21)
    {
        char choice;
        std::cout << "Otatko kortin (k/e)? ";
        std::cin >> choice;

        if (choice == 'k')
        {
            pelaaja.otaKortti();
            std::cout << "Sinulla on nyt " << pelaaja.pisteet << " pistett‰\n";
        }
        else {
            break;
        }
    }

    // Jakajan vuoro
    while (jakaja.pisteet < 17)
    {
        jakaja.otaKortti();
    }

    std::cout << "Jakajalla on " << jakaja.pisteet << " pistett‰\n";

    // Tuloksen tarkistus
    if (pelaaja.pisteet > 21) {
        std::cout << "Menit yli 21 Jakaja voittaa\n";
    }
    else if (jakaja.pisteet > 21) {
        std::cout << "Jakaja meni yli 21, sin‰ voitat\n";
    }
    else if (pelaaja.pisteet > jakaja.pisteet) {
        std::cout << "Sin‰ voitit!\n";
    }
    else {
        std::cout << "Jakaja voitti!\n";
    }

    return 0;
}
