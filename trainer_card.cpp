#include "trainer_card.h"

TrainerCard::TrainerCard() : TrainerEffect("default effect") {
    // Constructeur par défaut : l'effet par défaut est "default effect"
}

TrainerCard::TrainerCard(const std::string& effect) : TrainerEffect(effect) {
    // Constructeur avec effet : on initialise avec l'effet donné
}

void TrainerCard::displayInfo() const {
    std::cout << "Trainer card effect: " << TrainerEffect << std::endl;
}

void TrainerCard::applyEffect(std::vector<PokemonCard>& activePokemons) const {
    // Ici, tu appliques l'effet spécifique à la carte
    std::cout << "Applying effect: " << TrainerEffect << std::endl;
    // Exemple d'effet : guérir tous les Pokémon actifs, à adapter selon ton besoin
}

std::string TrainerCard::getEffect() const {
    return TrainerEffect;
}
