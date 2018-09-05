//
// Created by Parker Brown on 9/3/18.
//

#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <vector>
#include <string>
#include "Deck.h"
#include "Card.h"

class Player {
    Deck *deck = nullptr;
    std::vector<Card*> cards;
    std::string name;

public:
    Player(Deck *newDeck);

    void hit();
    void stand();
    void give(Card* card);
    void setName(std::string newName);
    std::string getName() const;
    void reset();

    int getTotalValue();
};

#endif //BLACKJACK_PLAYER_H
