#include <vector>
#include <string>

using namespace std;

class Pile {

public:
    Pile();
    string deal();

private:
    int cut;
    vector<string> playPile;
    vector<string> newPile;

    vector<string> makePile();
    vector<string> makeDeck();
    vector<string> shufflePile();

};