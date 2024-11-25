#include <tuple>
#include "headers/energy_card.h"

// Constructeur de la classe EnergyCard qui initialise le type d'énergie avec la valeur passée en paramètre.
EnergyCard::EnergyCard(const std::string& type) : energyType(type) {}

// Méthode pour afficher les informations de la carte d'énergie.
void EnergyCard::displayInfo() const {
    // Affiche le type de la carte d'énergie sur la sortie standard.
    std::cout << "Energy Card - Type: " << energyType << std::endl;
}