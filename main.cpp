#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include "header.h"

using namespace std;


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

