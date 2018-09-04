//
// Created by Parker Brown on 9/2/18.
//

#include <iostream>
#include <algorithm>
#include <time.h>
#include "Deck.h"

Deck::Deck() {
    for (int i = 0; i < 52; i++) {
        Card *newCard = new Card(i + 1);
        newCard->setSuite(static_cast<const Card::Suite>(i / 13));
        newCard->setRank(static_cast<const Card::Rank>((i % 13) + 1));
        cards.push_back(newCard);
    }
}

void Deck::shuffle() {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int newIndex = rand() % 52;
        cards[i]->setId(newIndex + 1);
        cards[newIndex]->setId(i + 1);
        std::swap(cards[i], cards[newIndex]);
    }
}

void Deck::reset() {
    cards.clear();
    for (int i = 0; i < 52; i++) {
        Card *newCard = new Card(i + 1);
        newCard->setSuite(static_cast<const Card::Suite>(i / 13));
        newCard->setRank(static_cast<const Card::Rank>((i % 13) + 1));
        cards.push_back(newCard);
    }
}

void Deck::print() const {
    for (Card *c : cards) {
        std::cout << c->toString() << std::endl;
    }
}

Card* Deck::get(int index) const {
    return cards.at(index);
}

Card* Deck::getLast() const {
    return cards.at(cards.size() - 1);
}

Card* Deck::drawLast() {
    Card *card = getLast();
    cards.pop_back();
    return card;
}

int Deck::count() const {
    return cards.size();
}
