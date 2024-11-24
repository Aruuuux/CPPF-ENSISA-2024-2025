#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include <string>
#include <iostream>
#include <vector>
#include "card.h"
#include "pokemon_card.h"

class TrainerCard : public Card {
protected:
    std::string TrainerEffect;  // Uniquement l'effet de la carte

public:
    // Constructeur par défaut sans nom
    TrainerCard();  // Ajout du constructeur par défaut

    // Constructeur avec effet
    TrainerCard(const std::string& effect);

    void displayInfo() const override;  // Affiche les informations de la carte
    void applyEffect(std::vector<PokemonCard>& activePokemons) const;  // Applique l'effet
    std::string getEffect() const override;  // Retourne l'effet de la carte
};

#endif // TRAINERCARD_H
