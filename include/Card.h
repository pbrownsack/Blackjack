//
// Created by Parker Brown on 9/2/18.
//

#ifndef BLACKJACK_CARD_H
#define BLACKJACK_CARD_H

#include <string>

class Card {
public:
    enum Rank {
        ACE = 1,
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        COUNT
    };

    enum Suite {
        SPADE = 0,
        HEART,
        CLUB,
        DIAMOND
    };

    Card();
    Card(int newId);

    void setId(const int newId);
    void setRank(const Rank newRank);
    void setSuite(const Suite newSuite);

    int getId() const;
    Rank getRank() const;
    Suite getSuite() const;
    char getSuiteChar() const;

    std::string toString() const;
private:
    int id = 1;
    Rank rank = ACE;
    Suite suite = SPADE;
};

#endif //BLACKJACK_CARD_H
