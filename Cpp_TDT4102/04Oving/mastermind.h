#pragma once

#define SIZE 4
#define LETTERS 6
#define MAX_GUESSES 10

void playMasterMind();
int checkGuessAndPos(string code, string guess);
int checkGuess(string code, string guess);