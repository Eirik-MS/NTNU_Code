#pragma once
#include "std_lib_facilities.h"
#include "Card.h"


class CardDeck {
    private:
        vector <Card> cards;

    public:
        CardDeck();
        void swap(int A, int B); //siden den er public kan man arve fra den
        void print();
        void shuffle();
        Card drawCard();
};

class BlackJack: public CardDeck {
    private:
        CardDeck deck;
        vector<Card> dealerHand;
        vector<Card> playerHand;
        int dealerSum;
        int playerSum;
    public:
        BlackJack(CardDeck stock, vector <Card> dH, vector <Card> pH, int dS, int pS);
        bool isAce(Card card);
        int getCardValue(Card card);
        int getHandScore(vector <Card> cards);
        bool askPlayerDrawCard();
        void drawPlayerCard();
        void drawDealerCard();
        void playGame();
};
