#include "std_lib_facilities.h"
#include "mastermind.h"
#include "utilities.h"




void playMasterMind(){
    string code = randomizeString(SIZE, 'A', 'A' + LETTERS - 1);
    string guess = readInputToString(SIZE, 'A', 'A' + LETTERS - 1);

    int guesses = 0;
    bool game = true;
    while(game){
        int correctPos = checkGuessAndPos(code, guess);
        int correct = checkGuess(code, guess);
        cout << "Correct letters: " << correct << endl;
        cout << "Correct letters and position: " << correctPos << endl;
        if (correctPos == SIZE){
            cout << "You won!" << endl;
            game = false;
        }
        else{
            guess = readInputToString(SIZE, 'A', 'A' + LETTERS - 1);
        }
        if (guesses == MAX_GUESSES){
            cout << "You lost!" << endl;
            game = false;
        }
        guesses++;
    }

}

int checkGuessAndPos(string code, string guess){
    int correctPos = 0;
    for (int i = 0; i < SIZE; i++){
        if (code[i] == guess[i]){
            correctPos++;
        }
    }
    return correctPos;
}

int checkGuess(string code, string guess){
    int correct = 0;
    for (int i = 0; i < SIZE; i++){
        correct += countChar(code, guess[i]);
    }
    return correct;
}