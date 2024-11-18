#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <string>
#include <vector>
#include <tuple>
#include "card.h"

class PokemonCard : public Card {
protected:
    std::string pokemonName;
    std::string pokemonType;
    std::string familyName;
    int evolutionLevel;

public:
    int hp;
    int maxHP;
    std::vector<std::tuple<int, int, std::string, int>> attacks;
    PokemonCard(
        const std::string& name, 
        const std::string& type, 
        const std::string& family, 
        int level, 
        int health, 
        int maxHealth, 
        const std::vector<std::tuple<int, int, std::string, int>>& attackList
    );
    int getHP() const;
    int getMaxHP() const;
    std::string getPokemonName() const { return pokemonName; }
    void displayInfo() const;
    void takeDamage(int damage);
};

#endif // POKEMON_CARD_H