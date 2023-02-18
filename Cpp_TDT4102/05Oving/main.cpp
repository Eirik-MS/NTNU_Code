
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.h"


int main()
{
	srand(unsigned(time(nullptr)));

    // Start black jack game
	CardDeck deck;
	vector <Card> spillerhand= {};
	vector <Card> dealerhand= {};
	BlackJack spill{deck,dealerhand,spillerhand,0,0};
    spill.playGame();

    return 0;
}