#include "headers/player.h"
#include "headers/energy_card.h" 
#include "headers/pokemon_card.h"
#include <iostream>

Player::Player(const std::string& name) : playerName(name) {}

void Player::displayInfo() const {
    std::cout << "Player Name: " << playerName << std::endl;
    std::cout << "Bench Cards:" << std::endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
    std::cout << "Action Cards:" << std::endl;
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::addBenchCard(Card* card) {
    //push_back permet d'ajouter un élément à la fin du vecteur
    benchCards.push_back(card);
}

void Player::addActionCard(PokemonCard* card) {
    actionCards.push_back(card);
}

void Player::removeBenchCard(Card* card) {
    for (auto it = benchCards.begin(); it != benchCards.end(); ++it) {
        if (*it == card) {
            benchCards.erase(it);
            break;
        }
    }
}

void Player::removeActionCard(PokemonCard* card) {
    for (auto it = actionCards.begin(); it != actionCards.end(); ++it) {
        if (*it == card) {
            actionCards.erase(it);
            break;
        }
    }
}

void Player::addCardToBench(Card* card) {
    addBenchCard(card);
}

void Player::activatePokemonCard(int index) {
    if (index >= 0 && index < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(benchCards[index]);
        if (pokemonCard) {
            addActionCard(pokemonCard);
            removeBenchCard(benchCards[index]);
        }
    }
}

void Player::attachEnergyCard(int benchIndex, int actionIndex) {
    if (benchIndex >= 0 && benchIndex < benchCards.size() && actionIndex >= 0 && actionIndex < actionCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[benchIndex]);
        if (energyCard) {
            removeBenchCard(benchCards[benchIndex]);
        }
    }
}

void Player::displayBench() const {
    std::cout << "Bench Cards:" << std::endl;
    for (const auto& card : benchCards) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(card);
        if (pokemonCard) {
            std::cout << "Pokemon Card: " << pokemonCard->getPokemonName() << ", HP: " << pokemonCard->hp << "/" << pokemonCard->getMaxHP() << std::endl;
        } else {
            EnergyCard* energyCard = dynamic_cast<EnergyCard*>(card);
            if (energyCard) {
                std::cout << "Energy Card: " << energyCard->getEnergyType() << std::endl;
            } else {
                std::cout << "Unknown Card Type" << std::endl;
            }
        }
    }
}

void Player::displayAction() const {
    std::cout << "Action Cards:" << std::endl;
    for (const auto& card : actionCards) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(card);
        if (pokemonCard) {
            std::cout << "Pokemon Card: " << pokemonCard->getPokemonName() << ", HP: " << pokemonCard->hp << "/" << pokemonCard->getMaxHP() << std::endl;
        } else {
            EnergyCard* energyCard = dynamic_cast<EnergyCard*>(card);
            if (energyCard) {
                std::cout << "Energy Card: " << energyCard->getEnergyType() << std::endl;
            } else {
                std::cout << "Unknown Card Type" << std::endl;
            }
        }
    }
}

void Player::attack(int attackerIndex, int attackIndex, Player& opponent, int targetIndex) {
    if (attackerIndex >= 0 && attackerIndex < actionCards.size() && targetIndex >= 0 && targetIndex < opponent.benchCards.size()) {
        PokemonCard* attacker = dynamic_cast<PokemonCard*>(actionCards[attackerIndex]);
        PokemonCard* target = dynamic_cast<PokemonCard*>(opponent.benchCards[targetIndex]);
        if (attacker && target) {
            // Logique pour effectuer l'attaque
            std::cout << attacker->getPokemonName() << " attaque " << target->getPokemonName() << "!" << std::endl;
            // Exemple de réduction des HP du Pokémon cible
            target->hp -= std::get<1>(attacker->attacks[attackIndex]);
            if (target->hp <= 0) {
                std::cout << target->getPokemonName() << " est KO!" << std::endl;
                opponent.removeBenchCard(target);
            }
        }
    }
}

void Player::useTrainer(int trainerIndex) {
    if (trainerIndex >= 0 && trainerIndex < actionCards.size()) {
        Card* trainerCard = actionCards[trainerIndex];
        // Logique pour utiliser la carte d'entraîneur
        std::cout << "Utilisation de la carte d'entraîneur!" << std::endl;
        // Exemple de suppression de la carte d'entraîneur après utilisation
        actionCards.erase(actionCards.begin() + trainerIndex);
    }
}