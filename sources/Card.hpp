#ifndef CARD_HPP
#define CARD_HPP

#include <string>
using std::string


class Card
{
private:
    int _value;
    string _color;
    string _type;
    string _specialName;

public:
    Card(int value, string color);

    int getValue();
    void printCard();
};


#endif // !CARD_HPP