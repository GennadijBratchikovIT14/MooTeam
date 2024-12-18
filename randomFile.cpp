#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "header.h"
using namespace std;

int countBullsAndCows(const string& secret, const string& guess) {
    int bulls = 0, cows = 0;
    bool secretUsed[4] = {false};

    for (int i = 0; i < guess.length(); i++) {
        if (guess[i] == secret[i]) {
            bulls++;
            secretUsed[i] = true;
        }
    }

    for (int i = 0; i < guess.length(); i++) {
        if (guess[i] != secret[i]) {
            for (int j = 0; j < secret.length(); j++) {
                if (!secretUsed[j] && guess[i] == secret[j]) {
                    cows++;
                    secretUsed[j] = true;
                    break;
                }
            }
        }
    }

    return bulls * 10 + cows;
}
