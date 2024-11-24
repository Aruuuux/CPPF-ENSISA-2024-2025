#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H
#include <iostream> 
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
    
    // Constructeur
    PokemonCard(
        const std::string& name, 
        const std::string& type, 
        const std::string& family, 
        int level, 
        int health, 
        int maxHealth, 
        const std::vector<std::tuple<int, int, std::string, int>>& attackList
    );

    // Méthodes existantes
    int getHP() const { return hp; }
    int getMaxHP() const { return maxHP; }
    
    std::string getType() const { return pokemonType; }
    
    std::string getPokemonName() const { return pokemonName; }
    
    // Retourne l'attaque à l'index donné
    std::tuple<int, int, std::string, int> getAttack(int moveIndex) const;

    void displayInfo() const override;
    void takeDamage(int damage);
    void heal();
    void attack(PokemonCard& opponent, int attackIndex);
};

#endif // POKEMON_CARD_H
