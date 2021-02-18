#include "BullsAndCows.h"
#include <iostream>

using std::nothrow;

void getBullsAndCows(int guess, int answer, int& bulls, int& cows) {
    int posGuess = 0;

    while (guess > 0) {
        int tmpAnswer = answer;
        int posAnswer = 0;

        while (tmpAnswer > 0) {
            if (guess % 10 == tmpAnswer % 10) {
                if (posGuess == posAnswer) {
                    bulls++;
                }
                else {
                    cows++;
                }
                break;
            }
            tmpAnswer /= 10;
            posAnswer++;
        }

        guess /= 10;
        posGuess++;
    }
}

const int* tryGuess(int guess) {
    int answer = 9876;

    int* resp = new (nothrow) int[2];
    if (!resp) {
        delete[] resp;
        return nullptr;
    }

    int bulls = 0;
    int cows = 0;

    getBullsAndCows(guess, answer, bulls, cows);

    resp[0] = bulls;
    resp[1] = cows;

    return resp;
}