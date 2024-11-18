#ifndef TRAINERCARD_H
#define TRAINERCARD_H

#include "card.h"
#include "pokemon_card.h"
#include <string>
#include <iostream>

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
                    pokemon.hp = pokemon.maxHP; 
                }
            }
        }; 

};
#endif // TRAINERCARD_H