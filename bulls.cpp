#include <iostream>
#include <string>
#include "header.h"

using namespace std;

bool isDigits(const string& str) {
    for (char i : str) {
        if(!isdigit(i)) {
            return false;
        }
    }
    return true;
}
