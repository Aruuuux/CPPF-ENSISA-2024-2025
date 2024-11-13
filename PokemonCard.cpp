#include "PokemonCard.h"


PokemonCard::PokemonCard(
    const std::string& name, 
    const std::string& type, 
    const std::string& family, 
    int level, 
    int health, 
    int maxHealth, 
    const std::vector<std::tuple<int, int, std::string, int>>& attackList
) : pokemonName(name), 
    pokemonType(type), 
    familyName(family), 
    evolutionLevel(level), 
    hp(health), 
    maxHP(maxHealth), 
    attacks(attackList) {}
