#include "pokemon_card.h"

// Constructeur de la classe PokemonCard qui initialise les attributs avec les valeurs passées en paramètre.
PokemonCard::PokemonCard(
    const std::string& name, const std::string& type, const std::string& family, 
    int level, int health, int maxHealth, 
    const std::vector<std::tuple<int, int, std::string, int>>& attackList)
    : pokemonName(name), pokemonType(type), familyName(family), evolutionLevel(level),
      hp(health), maxHP(maxHealth), attacks(attackList) {}

// Méthode pour afficher les informations de la carte Pokémon.
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon: " << pokemonName << " (Level " << evolutionLevel << ")\n";
    std::cout << "Type: " << pokemonType << "\n";
    std::cout << "HP: " << hp << "/" << maxHP << "\n";
    std::cout << "Attacks:\n";
    // Boucle pour afficher chaque attaque de la liste des attaques.
    for (size_t i = 0; i < attacks.size(); ++i) {
        auto attack = attacks[i];
        std::cout << "  Attack #" << i + 1 << ": " 
                  << std::get<2>(attack) << " (Cost: " 
                  << std::get<0>(attack) << ", Damage: " 
                  << std::get<3>(attack) << ")\n";
    }
}

// Méthode pour infliger des dégâts à la carte Pokémon.
void PokemonCard::takeDamage(int damage) {
    hp = std::max(0, hp - damage);  // Empêche les HP de devenir négatifs.
    std::cout << pokemonName << " took " << damage << " damage! Remaining HP: " << hp << "\n";
    if (hp == 0) {
        std::cout << pokemonName << " has fainted!\n";
    }
}

// Méthode pour soigner la carte Pokémon.
void PokemonCard::heal() {
    hp = maxHP;  // Restaure les HP à la valeur maximale.
    std::cout << pokemonName << " has been healed to full HP (" << maxHP << " HP)!\n";
}

// Méthode pour récupérer une attaque spécifique de la liste des attaques.
std::tuple<int, int, std::string, int> PokemonCard::getAttack(int attackIndex) const {
    if (attackIndex >= 0 && attackIndex < attacks.size()) {
        return attacks[attackIndex];
    }
    return {};  // Retourne un tuple vide si l'index est invalide.
}

// Méthode pour attaquer un autre Pokémon.
void PokemonCard::attack(PokemonCard& opponent, int attackIndex) {
    // Récupère l'attaque choisie.
    auto [cost, currentEnergy, description, damage] = getAttack(attackIndex);

    if (cost > currentEnergy) {
        std::cout << pokemonName << " doesn't have enough energy to perform " << description << "!\n";
        return;
    }

    // Applique les dégâts à l'adversaire.
    std::cout << pokemonName << " attacks " << opponent.getPokemonName() 
              << " with " << description << " for " << damage << " damage!\n";
    opponent.takeDamage(damage);  // L'attaque inflige des dégâts.
}