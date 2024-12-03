#include <iostream>
#include <string>
#include <ctime>
using namespace std;


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
            secret += (char) (temp + '0');
            count++;
        }
    }

    return secret;
}



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
                if (!secretUsed[j] and guess[i] == secret[j]) {
                    cows++;
                    secretUsed[j] = true;
                    break;
                }
            }
        }
    }

    return bulls * 10 + cows;
}


bool isDigits(const string& str) {
    for (char i : str) {
        if(!isdigit(i)) {
            return false;
        }
    }
    return true;
}




int main() {
    string secret = generateSecretNumber();
    cout << secret << endl;
    string guess;

    while (true) {
        cin >> guess;
        int result = countBullsAndCows(secret, guess);
        cout << result << endl;
    }
}
