#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include <string>
#include <vector>
#include <tuple>
#include <iostream>

class PokemonCard : public Card {
protected:
    std::string pokemonName;
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;
    std::vector<std::tuple<int, int, std::string, int>> attacks;

public:
    int hp;  // If hp <= 0, the Pokémon is considered "dead"
    int maxHP;
    int getMaxHP() const {
        return maxHP;
    }
    PokemonCard(
        const std::string& name, 
        const std::string& type, 
        const std::string& family, 
        int level, 
        int health, 
        int maxHealth, 
        const std::vector<std::tuple<int, int, std::string, int>>& attackList
    );

    
    void displayInfo() const {
        std::cout << "Name: " << pokemonName << std::endl;
        std::cout << "Type: " << pokemonType << std::endl;  
        std::cout << "Family: " << familyName << std::endl;
        std::cout << "Evolution Level: " << evolutionLevel << std::endl;
        std::cout << "HP: " << hp << std::endl;
        std::cout << "Max HP: " << maxHP << std::endl;
        std::cout << "Attacks:" << std::endl;
        for (const auto& attack : attacks) {
            std::cout << "  Energy Cost: " << std::get<0>(attack) << std::endl;
            std::cout << "  Current Energy Cost: " << std::get<1>(attack) << std::endl;
            std::cout << "  Description: " << std::get<2>(attack) << std::endl;
            std::cout << "  Damage: " << std::get<3>(attack) << std::endl;
        }
    }
};

#endif // POKEMONCARD_H
