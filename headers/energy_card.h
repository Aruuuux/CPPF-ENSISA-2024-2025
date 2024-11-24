#ifndef ENERGYCARD_H
#define ENERGYCARD_H
#include <string>
#include <iostream>
#include "card.h"

class EnergyCard : public Card {
protected:
    std::string energyType;

public:
    EnergyCard(const std::string& type);

    std::string getEnergyType() const { return energyType; }
    void setEnergyType(const std::string& type) { energyType = type; }

    // Déclaration de displayInfo sans la définition ici
    void displayInfo() const override; 
};

#endif // ENERGYCARD_H
