#ifndef CARD_H
#define CARD_H

#include <string>

class Card {
public:
    std::string cardName;

    
    Card() : cardName("Default Name") {}  
    
    
    Card(const std::string& name) : cardName(name) {}

    
    virtual void displayInfo() const = 0;
};

#endif // CARD_H
