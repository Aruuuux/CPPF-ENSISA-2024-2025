#include "headers/trainer_card.h"


void TrainerCard::displayInfo() const {
    std::cout << "Name: " << cardName << std::endl;
    std::cout << "Trainer Effect: " << TrainerEffect << std::endl;
}

void TrainerCard::applyEffect(std::vector<PokemonCard>& activePokemons) const {
    if (TrainerEffect == "heal all your action pokemon") {
        for (auto& pokemon : activePokemons) {
            pokemon.hp = pokemon.getMaxHP(); 
        }
    }
}
