#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "Card.h"
#include "PokemonCard.h"
#include <string>
#include <iostream> // Add missing import

class TrainerCard : public Card {
    protected:
        std::string TrainerEffect;

    public:
        TrainerCard(const std::string& name, const std::string& effect){ 
            cardName = name;
            TrainerEffect = effect;
        };

        void displayInfo() const{
            std::cout << "Name: " << cardName << std::endl;
            std::cout << "Trainer Effect: " << TrainerEffect << std::endl;
        };


        void applyEffect(std::vector<PokemonCard>& activePokemons) const { 
            if (TrainerEffect == "heal all your action pokemon") { 
                for (auto& pokemon : activePokemons) {
                    pokemon.hp = pokemon.maxHP; //heal all pokemon to max hp
                }
            }
        }; 

};
#endif // TRAINERCARD_H