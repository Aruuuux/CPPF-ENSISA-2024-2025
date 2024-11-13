#include  "Card.h"
#include <string>
#include <vector>
#include <tuple>

class PokemonCard : public Card{
    public:
        std::string pokemonType;
        std::string familyName;
        int evolutionLevel;
        int hp;
        int maxHP;
        std::vector<std::tuple<int, int, std::string, int>> attacks;
        int energyCost;
        int currentEnergyCost;
        std::string attackDescription;
        int attackDamage;
        
};