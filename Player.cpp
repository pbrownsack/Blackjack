//
// Created by Parker Brown on 9/3/18.
//

#include <iostream>
#include "Player.h"

Player::Player(Deck *newDeck) {
    deck = newDeck;
}

void Player::hit() {
    if (deck == nullptr) { return; }

    Card *newCard = deck->drawLast();
    cards.push_back(newCard);

    std::cout << "\n" << name << " hits for [" << newCard->getRank() << "]" << std::endl;
}

void Player::setName(std::string newName) {
    name = newName;
}

int Player::getTotalValue() {
    int total = 0;
    for (Card *card : cards) {
        total += card->getRank();
    }

    return total;
}

void Player::reset() {
    cards.clear();
}

std::string Player::getName() const {
    return name;
}

void Player::give(Card *card) {
    cards.push_back(card);
}
