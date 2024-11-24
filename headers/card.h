#ifndef CARD_H
#define CARD_H

#include <string>
#include <tuple>

class Card {
protected:
    std::string cardName;

public:
    // Déclaration d'une méthode virtuelle pure
    virtual void displayInfo() const = 0; // Pure virtual function
    virtual std::string getEffect() const { return ""; }  // Méthode par défaut qui retourne une chaîne vide
    virtual ~Card() = default;  // Destructeur virtuel pour assurer la destruction correcte des objets dérivés
};

#endif // CARD_H
