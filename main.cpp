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
    cout << setw(50) << setfill('=') << "\n";
    cout << "Игра \"Быки и коровы\"\n";
    cout << setw(50) << setfill('=') << "\n";

    string secret = generateSecretNumber();
    string guess;
    int attempts = 0;

    cout << "Компьютер загадал четырехзначное число с уникальными цифрами.\n";
    cout << "Ваша задача — угадать его. После каждой попытки будет выдано количество \"быков\" и \"коров\".\n\n";

    while (true) {
        cout << "Введите вашу догадку: ";
        cin >> guess;

        // Проверка корректности ввода
        if (guess.length() != 4 || !isDigits(guess)) {
            cout << "Ошибка: введите ровно 4 цифры.\n";
            continue;
        }

        ++attempts;
        int result = countBullsAndCows(secret, guess);

        cout << "Быки: " << result / 10 << ", Коровы: " << result % 10 << "\n";

        if (result / 10 == 4) {
            cout << "Поздравляем! Вы угадали число " << secret << " за " << attempts << " попыток.\n";
            break;
        }
    }

    return 0;
}










