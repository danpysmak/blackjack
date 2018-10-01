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
    Pile pile;
    pair<int,int> limits;

    int bet;
    int bank;

    vector<string> dealerCards;
    int dscore;
    vector<string> playerCards;
    int pscore;


    void setBank();
    void placeBet();

    void playRound();
    void displayCards(int mode);
    void showResults();
    void clearTable();

    void playDealer();
    bool playUser();
    bool waitUser();




    int countScore(vector<string> cards);

};