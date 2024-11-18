#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "card.h"
#include <string>
#include <iostream>

class EnergyCard : public Card {
protected:
    std::string energyType;

public:
    
    EnergyCard(const std::string& type);

    
    std::string getEnergyType() const { return energyType; }


    void setEnergyType(const std::string& type) { energyType = type; }

    
    void displayInfo() const {
        std::cout << "Energy Type: " << energyType << std::endl;
    };
};

#endif 
