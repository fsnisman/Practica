#include <iostream>
#include <cstdlib>
using namespace std;
//======================================================================================================================
class Cards{
private:
    Rank m_Rank;
    Suit m_Suit;
    bool m_IsFaceUp;
public:
    enum Suit{
        SPADES, HEARTS, DIAMONDS, CLUBS
    };
    enum Rank{
        ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
        JACK, QUEEN, KING
    };
    Card(rank r, suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu){}
    int getValue() const{
        //если карта перевернута лицом вниз, ее значение равно 0
        int value = 0;
        if (m_IsFaceUp){
            //значение на карте
            value = m_Rank;
            //значение равно для 10 JACK, QUEEN, KING
            if (value > 10){
                value = 10;
            }
        }
        return value;
    }
    void Flip(){
        m_IsFaceUp = !(m_IsFaceUp)
    }
};
class Hand{
protected:
    vector<Card*> m_Cards;
public:
    Hand(){
        m_Cards.reserve(7)
    };
    //виртуальный деструктор
    virtual ~Hand(){
        Clear()
    };
    //добавляет карту в руку
    void Add(Card* pCard){
        m_Cards.push_back(pCard)
    };
    //очишает руку от карт
    void Clear(){
        //проходит по векртору, освобождая память
        vector<Card*>::iterator iter = m_Cards.begin();
        for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter)
        {
            delete *iter;
            *iter = 0;
        }
        //очищает вектор указатлей
        m_Cards.clear();
    };
    int getTotal(){
        //если карт в руке нет, возращает значение 0
        if (m_Cards.empty()){
            return 0;
        }
        if (m_Cards[0]->GetValue() == 0){
            return 0;
        }
        //находим сумму очков всех карт, каждый туз дает 1 очко
        int total = 0;
        vector<Cards*>::const_iterator iter;
        for (iter = m_Cards.bagin(); iter != m_Cards.end(); ++iter){
            total += (*iter)->GetValue();
        }
        //определяет, держит ли рука туз
        bool containsAse = false;
        for (iter = m_Cards.begin(); iter != m_Cards.eds(); ++iter){
            if ((*iter)->GetValue() == ACE){
                containsAse = true;
            }
        }
        //если рука держит туз и сумма довольно маленькая, туз дает 11 очков
        if (containsAse && total <= 11){
            //добавляем только 10 очков, поспольку мы уже добавли
            //за каждый туз по одному очку
            total += 10;
        }
        return total;
    }                                   //получает сумму очков карт в руке. присваеваем значение тузу 1 или 11 по ситуаци
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
    string Name;
public:
    virtual bool IsHitting() const{
        if (total < 21){
            Add(Cards* total);
            return total;
        }
    };
    bool IsBoosted() const{
        if (total > 21){
            return false;
        }
        else {
            return bool;
        }
    };
    void Bust() const{
        if (IsBoosted() == false) {
            cout << Name << " " << "Enumeration of cards" << endl;
        }
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
