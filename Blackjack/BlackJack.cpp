#include <iostream>
#include <cstdlib>
using namespace std;

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
    Cards(rank r, suit s, bool ifu): m_Rank(r), m_Suit(s), m_IsFaceUp(ifu){}
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
    friend ostream& operator<< (ostream& os, const Cards& aCard);
};
ostream& operator<< (ostream& os, const Cards& aCard){
    const string RANKS[] = {"0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    if (aCard.m_IsFaceUp){
        os << RANKS[aCard.m_Rank] << SUITS [aCard.m_Suit];
    }
    else{
        os << "XX";
    }
    return os;
}

class Hand{
protected:
    vector<Cards*> m_Cards;
public:
    Hand(){
        m_Cards.reserve(7)
    };
    //виртуальный деструктор
    virtual ~Hand(){
        Clear()
    };
    //добавляет карту в руку
    void Add(Cards* pCard){
        m_Cards.push_back(pCard)
    };
    //очишает руку от карт
    void Clear(){
        //проходит по векртору, освобождая память
        vector<Cards*>::iterator iter = m_Cards.begin();
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

//абстрактный класс
class GenericPlayer: public Hand{
    friend ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer);
public:
    GenericPlayer(const string& Name = ""): m_Name(Name){};
    virtual ~GenericPlayer();

    // показывает, хочет ли игрок продолжать брать карты
    // Для класса GenericPlayer функция не имеет своей реализации,
    // т.к. для игрока и дилера это будут разные функции
    virtual bool IsHitting() const = 0;

    // возвращает значение, если у игрока перебор -
    // сумму очков большую 21
    // данная функция не виртуальная, т.к. имеет одинаковую реализацию
    // для игрока и дилера
    bool IsBoosted() const{
        return (GetTotal() > 21);
    };

    // объявляет, что игрок имеет перебор
    // функция одинакова как для игрока, так и для дилера
    void Bust() const{
        cout << m_Name << " " << "Enumeration of cards\n";
    };
protected:
    string m_Name;
};
ostream& operator<< (ostream& os, const GenericPlayer& aGenericPlayer){
    os << aGenericPlayer.m_Name << ":\t";
    vector<Card*>::const_iterator pCard;
    if(!aGenericPlayer.m_Cards.empti()){
        for (pCard = aGenericPlayer.m_Cards.begin; pCard != aGenericPlayer.m_Cards.end(); ++pCard){
            os << *(*pCard) << "\t";
        }
        if (aGenericPlayer.GetTotal() != 0){
            cout << "(" << aGenericPlayer.GetTotal() << ")";
        }
    }
    else{
        os << "<empty>";
    }
    return os;
}

class Player: public GenericPlayer{
public:
    Player(const string& Name = "");
    virtual  ~Player();

    // показывает, хочет ли игрок продолжать брать карты
    virtual bool IsHitting() const{
        cout << m_Name << ", do you want a hit? (Y/N)";
        char response;
        cin >> response;
        return (response == 'y' || response == 'Y');
    };

    // объявляет, что игрок победил
    void Win() const{
        cout << m_Name << " wins.\n";
    };

    // объявляет, что игрок проиграл
    void Lose() const{
        cout << m_Name << " loses.\n";
    };

    // объявляет ничью
    void Push() const{
        cout << m_Name << " pushes.\n";
    };
};

class House: public GenericPlayer{
public:
    House(const string& name = "House");
    virtual ~House();

    // показывает, хочет ли дилер продолжать брать карты
    virtual bool isHitting(){
        return (GetTotal() <= 16);
    };

    // переворачивает первую карту
    void FlipFirstCard(){
        if (!(m_Cards.empty())){
            m_Cards[0]->Flip();
        };
        else{
            cout << "No card to flip!\n"
        }
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
