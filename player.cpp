#include "player.h"
#include <iostream>

// Constructeur de la classe Player qui initialise le nom du joueur.
Player::Player(const std::string& name) : name(name) {}

// Méthode pour ajouter une carte au banc du joueur.
void Player::addCardToBench(Card* card) {
    bench.push_back(card);
}

// Méthode pour activer une carte Pokémon du banc et l'ajouter aux cartes d'action.
void Player::activatePokemonCard(int index) {
    if (index < bench.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(bench[index]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
        }
    }
}

// Méthode pour afficher les cartes sur le banc du joueur.
void Player::displayBench() const {
    std::cout << "Bench Cards for Player " << name << ":\n";
    for (const auto& card : bench) {
        card->displayInfo();
    }
}

// Méthode pour afficher les cartes d'action du joueur.
void Player::displayAction() const {
    std::cout << "Action Cards:\n";
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

// Méthode pour utiliser une carte d'entraîneur du banc.
void Player::useTrainer(int index) {
    if (index < bench.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(bench[index]);
        if (trainerCard) {
            for (auto& card : actionCards) {
                card->heal();
            }
        }
    }
}

// Méthode pour obtenir les cartes d'action du joueur.
std::vector<PokemonCard*> Player::getActionCards() const {
    return actionCards;
}