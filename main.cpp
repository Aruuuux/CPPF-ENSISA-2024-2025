#include "player.h"
#include "pokemon_card.h"
#include "energy_card.h"
#include "trainer_card.h"
#include <iostream>
#include <vector>

int main() {
    // Création des joueurs
    Player player1("Hadi");
    Player player2("Germain");

    // Ajout de cartes au banc du joueur 1
    std::vector<std::tuple<int, int, std::string, int>> pikachuAttacks = {
        {1, 1, "Thunder Shock", 30},
        {2, 2, "Thunder Bolt", 50}
    };
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 1, 100, 100, pikachuAttacks));
    player1.addCardToBench(new TrainerCard("heal all your action pokemon"));

    // Ajout de cartes au banc du joueur 2
    std::vector<std::tuple<int, int, std::string, int>> bulbasaurAttacks = {
        {1, 1, "Leech Seed", 15},
        {2, 2, "Vine Whip", 25}
    };
    player2.addCardToBench(new TrainerCard("heal all your action pokemon"));
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 100, bulbasaurAttacks));

    // Activation des Pokémon
    player1.activatePokemonCard(0); // Pikachu
    player2.activatePokemonCard(1); // Bulbasaur

    // Affichage du banc et des actions des joueurs
    std::cout << "Player 1 Bench and Actions:\n";
    player1.displayBench();
    std::cout << std::endl;
    player1.displayAction();

    std::cout << "Player 2 Bench and Actions:\n";
    player2.displayBench();
    std::cout << std::endl;
    player2.displayAction();

    // Player 1 attaque Player 2
    std::cout << "\nPlayer 1 attacks Player 2:\n";
    if (!player2.getActionCards().empty()) {
        PokemonCard* activePokemon2 = player2.getActionCards()[0];
        if (activePokemon2) {
            activePokemon2->takeDamage(20);
            std::cout << "Pikachu attacks Bulbasaur with Thunder Bolt for 20 damage!\n";
        }
    }

    // Affichage des actions après l'attaque
    std::cout << "\nAction Cards:\n";
    player2.displayAction();

    // Utilisation de la carte Trainer (Brock) par le joueur 2
    std::cout << "\nAfter using Trainer Card (Brock):\n";
    player2.useTrainer(0);

    // Affichage des actions après l'utilisation de la carte Trainer
    std::cout << "Action Cards:\n";
    player2.displayAction();

    return 0;
}