#include <string>

using namespace std;

class Card
{
    private:
        string name;
        int mana_cost;
        int attack;
        int defense;
    
    public:
        Card(string name, int mana_cost, int attack, int defense);
        void display();
};