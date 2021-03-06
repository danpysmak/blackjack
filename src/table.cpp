#include "table.h"
#include <iostream>
#include <zconf.h>

Table::Table() : pile(Pile()), limits(2,500) {}

void Table::play() {

    setBank();
    string cont;
    while (true) {
        clearTable();
        playRound();

        cout << endl << "Do you wish to continue? (y/n)" << endl;
        cin >> cont;
        while (cont != "y" && cont != "n") {
            cout << "Invalid input. Please enter \"y\" for yes or \"n\" for no." << endl;
            cin >> cont;
        }
        if (cont == "y") {
            continue;
        } else if (cont == "n") {
            cout << "Good bye!";
            break;
        }
    }
}

void Table::playRound() {

    placeBet();

    for (int i = 0; i < 2; ++i) {
        playerCards.push_back(pile.deal());
        dealerCards.push_back(pile.deal());
    }

    pscore = countScore(playerCards);
    dscore = countScore(dealerCards);

    displayCards(0);

    if (!playUser())
        return;
    playDealer();

    showResults();

}







void Table::setBank() {
    cout << "Please enter how much cash you want to bring to the table:" << endl << "$";
    int playersBank;
    cin >> playersBank;

    while (playersBank < 2) {
        cout << "Minimum bet is $2, you cant play with less money." ;
        cout << "Please enter how much cash you want to bring to the table:" << endl << "$";
        cin >> playersBank;
    }

    bank = playersBank;

}

void Table::placeBet() {
    int currBet;
    while (true) {
        cout << "Place your bet:" << endl << "$";
        cin >> currBet;
        if (currBet >= limits.first && currBet <= limits.second) {
            break;
        } else {
          cout << "The bet you are trying to place is out of the limits. Limits for this game are $" << limits.first
               << " to $" << limits.second << ". Try again." << endl;

        }
    }

    bank -= currBet;
    bet = currBet;
    cout << endl << endl;
}



int Table::countScore(vector<string> cards) {

    int score = 0;
    unordered_set<string> tens = {"10", "J", "Q", "K"};

    for (string card : cards) {
        string value = card.substr(0, card.size()-3);   // kind symbol string has a size of 3
        if (tens.find(value) != tens.end()) {
            score += 10;
        } else if (value == "A") {
            score += 11;
        } else {
            score += stoi(value);
        }
    }

    return score;

}

void Table::displayCards(int mode) {
    cout << endl << endl;
    cout << "Dealer's hand:  " ;

    if (mode == 0) {
        cout << dealerCards[0] << " [X]";
    } else {
        for (int i = 0; i < dealerCards.size(); ++i) {
            cout << dealerCards[i] << " ";
        }
    }

    cout << endl << endl << endl << endl;

    cout << "Your hand:      " ;
    for (int i = 0; i < playerCards.size(); ++i) {
        cout << playerCards[i] << " ";
    }
    cout << endl << endl;

    cout << "Bank: $" << bank << "    Current bet: $" << bet << endl << endl;
}




bool Table::playUser() {
    while (pscore <= 21) {
        if (waitUser()) {
            playerCards.push_back(pile.deal());
            pscore = countScore(playerCards);
            displayCards(0);
        } else {
            break;
        }
    }

    if (pscore > 21) {
        cout << "You went bust! Round is over." << endl;
        cout << "Your bank is now $" << bank << endl;
        return false;
    } else {
        cout << "Dealer's turn." << endl;
        return true;
    }
}

bool Table::waitUser() {
    cout << "Hit SPACE to draw, ENTER to stand" << endl;

    while (true) {
        string input;
        cin >> input;
        if (input == "s") {
            return true;
        } else if (input == "e") {
            return false;
        }
    }
}

void Table::playDealer() {
    displayCards(1);
    while (dscore < 17) {
        sleep(2);
        dealerCards.push_back(pile.deal());
        dscore = countScore(dealerCards);
        displayCards(1);
    }
}





void Table::showResults() {
    if (dscore > 21) {
        cout << "Dealer went bust! You won." << endl;
        bank += bet * 2;
    } else if (pscore > dscore) {
        cout << "You won! (You scored " << pscore << ". Dealer scored " << dscore << ".)" << endl;
        bank += bet * 2;
    } else if (pscore < dscore) {
        cout << "You lost! (You scored " << pscore << ". Dealer scored " << dscore << ".)" << endl;
    } else {
        cout << "It's a tie! (You both scored " << pscore << ")" << endl;
        bank += bet;
    }


    cout << "Your bank is now $" << bank << endl;
}

void Table::clearTable() {
    pscore = 0;
    dscore = 0;
    playerCards.clear();
    dealerCards.clear();
    bet = 0;
}