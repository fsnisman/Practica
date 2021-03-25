#include <iostream>
#include <cstdlib>
using namespace std;
//======================================================================================================================
enum Suit{
    Card_Peaks = "peaks",
    Card_Hearts = "hearts",
    Card_Diamonds = "diamonds",
    Card_Clubs = "clubs"
};
enum Value{
    Card_Value2 = 2,
    Card_Value3 = 3,
    Card_Value4 = 4,
    Card_Value5 = 5,
    Card_Value6 = 6,
    Card_Value7 = 7,
    Card_Value8 = 8,
    Card_Value9 = 9,
    Card_Value10 = 10,
    Card_Jack = 2,
    Card_Lady = 3,
    Card_King = 4,
    Card_Ace1 = 1,
    Card_Ace11 = 11
};
//======================================================================================================================
class Cards{
protected:
    Suit suit;
    Value value;
    bool flip_card;
    int source = 0;
public:
    bool Flip(){
        if (flip_card == 0){
            return flip_card = 1;
        }
        else (flip_card == 1){
            return  flip_card = 0;
        }
    }
    int getValue(){
        return value;
    }
};
class Hand{
protected:
public:
};
class Deck: public Hand{
private:
public:
};
class GenericPlayer: public Hand{
protected:
public:
};
class Player: public GenericPlayer{
private:
public:
};
class House: public GenericPlayer{
private:
public:
};
class Game{
private:
public:
};

int main() {
    return 0;
}
