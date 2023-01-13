import random



def draw_card(player, cards):
    decklen = len(cards)
    draw = cards[random.randint(0, decklen-1)]
    if draw == 11:
        if player + draw > 21:
            draw = 1 
    return draw

def check_win(player, dealer):
    if player > 21:
        print("You lose")
    elif player > dealer or dealer > 21:
        print("You win")
    elif player == dealer:
        print("Draw")
    else:
        print("You lose")
    return 


def play():
    cards = [2,3,4,5,6,7,8,9,10,10,10,10,11]
    player = draw_card(0, cards) + draw_card(0, cards)
    dealer = draw_card(0, cards)
    print(f'Dealer has {dealer} and a hidden card\nYour socre is {player}')
    dealer += draw_card(dealer, cards)
    while True:
        match input("Do you want to draw another card? (y/n)"):
            case "y":  
                player += draw_card(player, cards)
                print(f'Your score is {player}')
            case "n":
                check_win(player, dealer)
                break
    return

play()
print("start")

