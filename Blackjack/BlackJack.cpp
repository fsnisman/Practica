#include <iostream>
#include <cstdlib>
using namespace std;
//======================================================================================================================
enum Suit{
    Card_Peaks = 1,
    Card_Hearts = 2,
    Card_Diamonds = 3,
    Card_Clubs = 4
};
enum Rank{
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
    Card_Ace = 1 | 11,
};
//======================================================================================================================
class Cards{
protected:
    Rank m_Rank;
    Suit m_Suit;
    bool IsFaceUp;
    int source = 0;
public:
    bool m_IsFaceUp() const{            // 0 - рубашкоой, 1 - лицо
        if (IsFaceUp == 0){
            return IsFaceUp = 0;
        }
        else (IsFaceUp == 1){
            return  IsFaceUp = 1;
        }
    }
    int getValue() const{
        return value;
    }
    void Flip(){
        if (IsFaceUp == 0){
            return IsFaceUp = 1;
        }
        if (IsFaceUp == 1){
            return IsFaceUp = 0;
        }
    }
};
class Hand{
private:
    vector<Card*> m_Cards;
public:
    void Add(Card* pCard){
        m_Cards.push_back(pCard);

    };
    void Clear(){
        m_Cards.clear();
    };
    int getTotal(){
        m_Rank += source;
        return source;
    }
};
class Deck: public Hand{
public:
    void Populate(){

    };
    void Shuffle(){

    };
    void Deal (Hand& aHand){

    };
    void AddItionalCards(GenericPlayer&aGenerIcPlayer){

    };
};
class GenericPlayer: public Hand{
private:
    string m_Name;
public:
    virtual bool IsHitting() const = 0;
    bool IsBoosted() const{

    };
    void Bust() const{

    };
};
class Player: public GenericPlayer{
public:
    virtual bool IsHitting() const{

    };
    void Win() const{

    };
    coid Lose() const{

    };
    void Push() const{

    };
};
class House: public GenericPlayer{
public:
    virtual bool isHitting(){

    }
    void FlipFirstCard(){

    };
};
class Game{
private:
    Deck m_Deck;
    House m_House;
    vector<Player> m_Players;
public:
    void Play(){

    };
};

int main() {
    return 0;
}
