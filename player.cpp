#include "player.h"
#include <iostream>

Player::Player(const std::string& name) : name(name) {}

void Player::addCardToBench(Card* card) {
    bench.push_back(card);
}

void Player::activatePokemonCard(int index) {
    if (index < bench.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(bench[index]);
        if (pokemonCard) {
            actionCards.push_back(pokemonCard);
        }
    }
}

void Player::displayBench() const {
    std::cout << "Bench Cards for Player " << name << ":\n";
    for (const auto& card : bench) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action Cards:\n";
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

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

std::vector<PokemonCard*> Player::getActionCards() const {
    return actionCards;
}