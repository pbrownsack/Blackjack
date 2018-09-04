#include <iostream>
#include <string>
#include "Card.h"
#include "Deck.h"
#include "Game.h"

int main() {
    Game game;

    std::cout << "Welcome to Blackjack v1.0!" << std::endl;
    std::cout << "Created by Parker Brown" << std::endl;
    std::cout << "==========================" << std::endl << std::endl;

    std::string name;

    std::cout << "What would you like to be called? ";
    getline(std::cin, name);

    game.getHuman()->setName(name);
    std::cout << "\nYou chose " << name << " as your name." << std::endl << std::endl;

    game.newGame();
    return 0;
}