#include "pile.h"
#include <iostream>


Pile::Pile() : newPile(makePile()), cut(65) {
    playPile = shufflePile();
}

vector<string> Pile::makeDeck() {

    string cards[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"};
    string kinds[4] = {"♣", "♥", "♠", "♦"};

    vector<string> deck;
    deck.reserve(52);

    for (string kind : kinds) {
        for (string card : cards) {
            string card_el = card + kind;
            deck.push_back(card_el);
        }
    }

    return deck;
}


vector<string> Pile::makePile() {

    vector<string> deck = makeDeck();

    vector<string> pile;
    pile.reserve(312);

    for (int i = 0; i < 6; ++i) {
        for (string card : deck) {
            pile.push_back(card);
        }
    }

    return pile;
}


vector<string> Pile::shufflePile() {

    vector<string> shuffledPile = newPile;
    random_shuffle(shuffledPile.begin(), shuffledPile.end());
    return shuffledPile;
}

string Pile::deal() {

    if (playPile.size() <= cut) {
        shufflePile();
        cout << "Shuffling the pile ..." << endl;
    }

    string card = playPile[playPile.size()-1];
    playPile.pop_back();

    return card;
}