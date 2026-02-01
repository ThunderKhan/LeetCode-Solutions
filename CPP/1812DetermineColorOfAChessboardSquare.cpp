#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool squareIsWhite(string coordinates) {
    int col = coordinates[0] - 'a' + 1;
    int row = coordinates[1] - '0';

    int sum = col + row;

    if (sum % 2 == 1) {
        return true;
    }
    return false;
}