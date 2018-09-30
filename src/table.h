#include <vector>
#include <string>
#include <unordered_set>
#include "pile.h"

using namespace std;

class Table {

public:
    Table();
    void play();


private:
    int bet;
    int bank;
    Pile pile;
    vector<string> dealerCards;
    int dscore;
    vector<string> playerCards;
    int pscore;

    void playRound();
    void displayCards(int mode);
    void showResults();
    void clearTable();

    void playDealer();
    bool playUser();

    void setBank();
    void placeBet();
    bool waitUser();


    int countScore(vector<string> cards);


};