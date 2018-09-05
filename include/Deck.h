//
// Created by Parker Brown on 9/2/18.
//

#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <string>

#include "Card.h"

class Deck {
    std::vector<Card*> cards{};

public:
    Deck();
    void shuffle();
    void reset();
    void print() const;

    Card* get(int index) const;
    Card* getLast() const;
    Card* drawLast();
    int count() const;
};

#endif //BLACKJACK_DECK_H
