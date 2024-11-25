#include "trainer_card.h"

TrainerCard::TrainerCard() : TrainerEffect("default effect") {
    // Constructeur par défaut 
}

TrainerCard::TrainerCard(const std::string& effect) : TrainerEffect(effect) {
    // Constructeur avec effet 
}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer card effect: " << TrainerEffect << std::endl;
}

void TrainerCard::applyEffect(std::vector<PokemonCard>& activePokemons) const {
    
    std::cout << "Applying effect: " << TrainerEffect << std::endl;
    // Exemple d'effet : guérir tous les Pokémon actifs
}

std::string TrainerCard::getEffect() const {
    return TrainerEffect;
}
