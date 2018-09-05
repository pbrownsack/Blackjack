//
// Created by Parker Brown on 9/2/18.
//

#include "../include/Card.h"

Card::Card(int newId) : id(newId) {}

void Card::setId(const int newId) {
    id = newId;
}

int Card::getId() const {
    return id;
}

Card::Rank Card::getRank() const {
    return rank;
}

void Card::setRank(const Card::Rank newRank) {
    rank = newRank;
}

Card::Suite Card::getSuite() const {
    return suite;
}

void Card::setSuite(const Card::Suite newSuite) {
    suite = newSuite;
}

std::string Card::toString() const {
    return "[" + std::to_string(id) + "] Suite: " + getSuiteChar() + ", Rank: " + std::to_string(rank);
}

char Card::getSuiteChar() const {
    switch(suite) {
        case 0:
            return 'S';
        case 1:
            return 'H';
        case 2:
            return 'C';
        case 3:
            return 'D';
        default:
            return '0';
    }
}
