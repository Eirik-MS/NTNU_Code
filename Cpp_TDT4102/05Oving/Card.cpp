#include "std_lib_facilities.h"
#include "Card.h"



string suitToString(Suit I){
    const std::map<Suit, std::string> suitMap = {
        {Suit::clubs, "clubs"},
        {Suit::diamonds, "diamonds"},
        {Suit::hearts, "hearts"},
        {Suit::spades, "spades"}
    };
    return suitMap.at(I);
};


string rankToString(Rank I){
    const std::map<Rank, std::string> rankMap = {
        {Rank::two, "two"},
        {Rank::three, "three"},
        {Rank::four, "four"},
        {Rank::five, "five"},
        {Rank::six, "six"},
        {Rank::seven, "seven"},
        {Rank::eight, "eight"},
        {Rank::nine, "nine"},
        {Rank::ten, "ten"},
        {Rank::jack, "jack"},
        {Rank::queen, "queen"},
        {Rank::king, "king"},
        {Rank::ace, "ace"}
    };
    return rankMap.at(I);
};

Card::Card(Suit suit, Rank rank): s{suit}, r{rank} {};

Suit Card::getSuit(){
    return s;
};

Rank Card::getRank(){
    return r;
}

string Card::toString(){
    string S = suitToString(s);
    string R = rankToString(r);
    string result = R + " of " + S;
    return result;
};