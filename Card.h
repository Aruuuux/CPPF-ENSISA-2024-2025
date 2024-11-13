#include <string>

class Card{
public: 
    std::string cardName;

    virtual void displayInfo() = 0;
};