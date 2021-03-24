#include <iostream>
#include <cstdlib>

using namespace std;

class Cards{
protected:
    int source = 0;
};
class Cards_number: public Cards{     //V etom classe nygen bydet random na chislo ot 2 do 10
private:
    int number_card = rand()% 10 +2;
public:
    void set_number_source() {
        source += number_card;
    }

};
class Cards_image: public Cards{
private:
    int image_card = 10;
public:
    void set_image_source(){
        source += image_card;
    }
};
class Cards_Ace: public Cards{
private:
    int ace_card = 11;
public:
    void set_ace_source(){
        source += ace_card;
    }
};

class Person: public Cards{
private:
    int source_dealer;
    int source_player;
public:
    void set_source_dealer(){
        source_dealer = source;
    }
    void set_source_player(){
        source_player = source;
    }
};

int main() {
    return 0;
}
