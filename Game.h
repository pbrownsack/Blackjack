//
// Created by Parker Brown on 9/3/18.
//

#ifndef BLACKJACK_GAME_H
#define BLACKJACK_GAME_H

#include "Deck.h"
#include "Player.h"

class Game {
    Deck *deck;
    Player *human;
    Player *dealer;
public:
    Game();
    void newGame();
    void think();
    void end(Player* ply);

    Player* getHuman() const;
    Player* getDealer() const;
};

#endif //BLACKJACK_GAME_H
