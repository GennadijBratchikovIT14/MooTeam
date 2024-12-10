#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>

string generateSecretNumber();
int countBullsAndCows(const string& secret, const string& guess);
bool isDigits(const string& str);

#endif // HEADER_H
