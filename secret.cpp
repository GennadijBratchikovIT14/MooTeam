#include "header.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>


string generateSecretNumber() {
    string secret = "";
    srand(time(NULL));
    int A[4] = {};
    int count = 0;

    while (count < 4) {
        int temp = rand() % 10;
        bool unique = true;

        for (int j = 0; j < count; j++) {
            if (A[j] == temp) {
                unique = false;
                break;
            }
        }

        if (unique) {
            A[count] = temp;
            secret += (char)(temp + '0');
            count++;
        }
    }

    return secret;
}
