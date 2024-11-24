#ifndef PLAYER_H
#define PLAYER_H

#include "card.h"
#include "pokemon_card.h"
#include "trainer_card.h"
#include <vector>
#include <string>

class Player {
public:
    Player(const std::string& name);
    void addCardToBench(Card* card);
    void activatePokemonCard(int index);
    void displayBench() const;
    void displayAction() const;
    void useTrainer(int index);
    std::vector<PokemonCard*> getActionCards() const;

private:
    std::string name;
    std::vector<Card*> bench;
    std::vector<PokemonCard*> actionCards;
};

#endif // PLAYER_H