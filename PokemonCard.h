#include  "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card{
    protected:
        std::string pokemonType;
        std::string familyName;
        int evolutionLevel;
        int hp; //if hp is <= 0, pokemon died and is removed from the game
        int maxHP;
        std::vector<std::tuple<int, int, std::string, int>> attacks;

    public:
        PokemonCard(
            std::string& name, 
            std::string& type, 
            std::string& family, 
            int level, 
            int health, 
            int maxHealth, 
            std::vector<std::tuple<int, int, std::string, int>>& attackList
        ); 
};