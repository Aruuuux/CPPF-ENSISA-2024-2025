#ifndef ENERGYCARD_H
#define ENERGYCARD_H

#include "Card.h"
#include <string>
#include <iostream>

class EnergyCard : public Card {
protected:
    std::string energyType;

public:
    // Constructeur
    EnergyCard(const std::string& name, const std::string& type);

    // Getter pour energyType
    std::string getEnergyType() const { return energyType; }

    // Setter pour energyType
    void setEnergyType(const std::string& type) { energyType = type; }

    // Affichage des informations de la carte énergie
    void displayInfo() const {
        std::cout << "Energy Type: " << energyType << std::endl;
    };
};

#endif // ENERGYCARD_H
