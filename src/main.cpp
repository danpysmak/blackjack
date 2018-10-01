#include <iostream>
#include "table.h"

using namespace std;

int main() {

    cout << "Welcome to Blackjack!" << endl << endl;
    cout << "Limits in this game are from $2 to $500" << endl << endl;

    Table table;
    table.play();

    return 0;
}


