#include "headers/pokemon_card.h"
#include <iostream>

PokemonCard::PokemonCard(
    const std::string& name, 
    const std::string& type, 
    const std::string& family, 
    int level, 
    int health, 
    int maxHealth, 
    const std::vector<std::tuple<int, int, std::string, int>>& attackList
) 
    : pokemonName(name), 
      pokemonType(type), 
      familyName(family), 
      evolutionLevel(level), 
      hp(health), 
      maxHP(maxHealth), 
      attacks(attackList) {}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

void PokemonCard::displayInfo() const {
    std::cout << "Name: " << pokemonName << std::endl;
    std::cout << "Type: " << pokemonType << std::endl;  
    std::cout << "Family: " << familyName << std::endl;
    std::cout << "Evolution Level: " << evolutionLevel << std::endl;
    std::cout << "HP: " << hp << " / " << maxHP << std::endl;

    std::cout << "Attacks:" << std::endl;
    for (const auto& attack : attacks) {
        std::cout << "  Energy Cost: " << std::get<0>(attack) << std::endl;
        std::cout << "  Damage: " << std::get<1>(attack) << std::endl;
        std::cout << "  Name: " << std::get<2>(attack) << std::endl;
    }
}

void PokemonCard::takeDamage(int damage) {
    hp -= damage;
    if (hp < 0) {
        hp = 0;
    }
}

int PokemonCard::getHP() const {
    return hp;
}
