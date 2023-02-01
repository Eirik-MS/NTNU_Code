

def hangman(word, life):
    word = word.lower()
    word = list(word)
    hidden_word = list(word)
    hidden_word = [x.replace(x, '*') for x in hidden_word]
    print(' '.join(hidden_word))
    while life > 0:
        letter = input('Guess a letter: ')
        letter = letter.lower()
        if letter in word:
            for i in range(len(word)):
                if word[i] == letter:
                    hidden_word[i] = letter
            print(' '.join(hidden_word))
            if word == hidden_word:
                print('You won!')
                break
        else:
            life -= 1
            print('Wrong! You have ' + str(life) + ' lives left')
            if life == 0:
                print('You lost!')
                break

hangman(input('Enter a word: '), int(input('Enter number of lives: ')))