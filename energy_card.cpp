#include <tuple>
#include "headers/energy_card.h"


EnergyCard::EnergyCard(const std::string& type) : energyType(type) {}


void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Type: " << energyType << std::endl;
}

