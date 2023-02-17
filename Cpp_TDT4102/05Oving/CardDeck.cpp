#include "std_lib_facilities.h"
#include "CardDeck.h"
#include "Card.h"


CardDeck::CardDeck(){
    for (int suit = 0; suit <= 3; suit++)
    {
        for (int rank = 2; rank <= 14; rank++)
        {
            cards.push_back(Card{(Suit)suit, (Rank)rank});
        }
    }

}

void CardDeck::swap(int idxA, int idxB){
    Card temp = cards[idxA];
    cards[idxA] = cards[idxB];
    cards[idxB] = temp;
}

void CardDeck::print(){
    cout << cards.size() << endl;
    for (int i = 0; i < cards.size(); i++){
        cout << i << "   " << cards[i].toString() << endl;
    }
}

void CardDeck::shuffle(){
    for (int i = 0; i < cards.size(); i++){
        int idxA = rand()%51; //lager tilfeldige tall mellom 0 og 51, siden kortstokken er 52 lang
        swap(i, idxA);
    }
}

Card CardDeck::drawCard(){
    Card drawn = cards[cards.size()-1];
    cards.pop_back();
    return drawn;
}

BlackJack::BlackJack(CardDeck stock, vector <Card> dH, vector <Card> pH, int dS, int pS){
    deck = stock;
    dealerHand = dH;
    playerHand = pH;
    dealerSum = dS;
    playerSum = pS;
}

bool BlackJack::isAce(Card card){
    if (int(Rank(card.getRank())) == 14){
        return true;
    } else {
        return false;
    }
}

int BlackJack::getCardValue(Card card){
    if (isAce(card) == true){
        return 11;
    } else if (int(Rank(card.getRank())) > 10){
        return 10;
    } else {
        return int(Rank(card.getRank()));
    }
}

int BlackJack::getHandScore(vector <Card> cards){
    int sum = 0;
    int aces = 0;
    for (int i = 0; i < cards.size(); i++){
        if (isAce(cards[i]) == true){
            aces += 1;
            sum += 1;
        } else {
            sum += getCardValue(cards[i]);
        }
    }
    if (aces > 0) {
        if (sum + 10 <= 21){
            sum += 10;
        }
    }
    return sum;
}

bool BlackJack::askPlayerDrawCard(){
    cout << "Do you want to draw? ( y | n ): \n";
    char answear;
    cin >> answear;
    if (answear == 'y'){
        return true;
    } else if (answear == 'n'){
        return false;
    } else {
        cout << "!! ERRORR !! Invalid input...\n";
        askPlayerDrawCard();
    }
}

void BlackJack::drawPlayerCard(){
    Card newCard = drawCard();
    playerHand.push_back(newCard);
    playerSum = getHandScore(playerHand);
}

void BlackJack::drawDealerCard(){
    Card newCard = drawCard();
    dealerHand.push_back(newCard);
    dealerSum = getHandScore(dealerHand);
}

void BlackJack::playGame(){
    shuffle();
    drawPlayerCard();
    drawPlayerCard();

    drawDealerCard();
    cout << "Dealer card: " << dealerHand[0].toString() << endl;
    drawDealerCard();
    if (playerSum < 21)
    {
        bool cont = true;
        while (playerSum < 21 && cont == true){
            cout << "Current points: " << playerSum << endl;
            cout << "Current hand: \n";
            for (int i = 0; i < playerHand.size(); i++){
                cout << playerHand[i].toString() << "  |  ";
            }
            cout << endl;
            cont = askPlayerDrawCard();
            if (cont == true){
                drawPlayerCard();
            }
        }
    }
    cout << "----- \n Current hand: \n";
    for (int i = 0; i < playerHand.size(); i++){
        cout << playerHand[i].toString() << "  |  ";
    }
    cout << endl;
    cout << "Player points: " << playerSum << endl;
    cout << "Dealer points: " << dealerSum << endl;

    while (dealerSum < 17){
        drawDealerCard();
        cout << "Dealer points: " << dealerSum << endl;
    }

    for (int i = 0; i < dealerHand.size(); i++){
        cout << dealerHand[i].toString() << "  |  ";
    }

    if (playerSum > 21 || (playerSum <= dealerSum && dealerSum < 22)){
        cout << "\nBeklager, du tapte\n";
    } else if (playerSum > dealerSum || dealerSum > 21) {
        cout << "\nGratulerer, du vant!\n";
    }
}