#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "pokemon_card.h"

class Player {
public:
    std::string playerName;
    std::vector<Card*> benchCards; 
    std::vector<PokemonCard*> actionCards; 

    Player(const std::string& name);

    void displayInfo() const;
    void displayBench() const;
    void displayAction() const;
    void addBenchCard(Card* card);
    void addActionCard(PokemonCard* card);
    void removeBenchCard(Card* card);
    void removeActionCard(PokemonCard* card);
    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void attachEnergyCard(int benchIndex, int actionIndex);
    void attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex);
    void useTrainer(int trainerIndex);
};

#endif // PLAYER_H