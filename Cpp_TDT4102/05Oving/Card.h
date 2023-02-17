#pragma once

enum class Suit {clubs = 1, diamonds = 2, hearts = 3, spades = 4};
enum class Rank {
    two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8, nine = 9, ten = 10, jack = 11, queen = 12, king = 13, ace = 14
    };

string suitToString(Suit I);
string rankToString(Rank I);

class Card {
    private:
        Suit s;
        Rank r;
    public:
        Card(Suit suit, Rank rank);
        Suit getSuit();
        Rank getRank();
        string toString();
};