//
// Created by Parker Brown on 9/3/18.
//

#include <iostream>
#include "Game.h"

Game::Game() {
    deck = new Deck();
    human = new Player(deck);
    dealer = new Player(deck);
    deck->shuffle();
    dealer->setName("Dealer");
}

Player* Game::getHuman() const {
    return human;
}

Player* Game::getDealer() const {
    return dealer;
}

void Game::newGame() {
    deck->reset();
    deck->shuffle();
    human->reset();
    dealer->reset();

    Card *card = deck->drawLast();
    std::cout << "The dealer shuffles the cards and deals a new hand." << std::endl;
    std::cout << "The dealer draws [" << card->getRank() << "]" << std::endl << std::endl;
    dealer->give(card);
    card = deck->drawLast();
    dealer->give(card);

    std::cout << dealer->getTotalValue() << std::endl;

    card = deck->drawLast();
    std::cout << human->getName() << " receives first card from dealer [" << card->getRank() << "]" << std::endl;
    human->give(card);

    card = deck->drawLast();
    std::cout << human->getName() << " receives second card from dealer [" << card->getRank() << "]" << std::endl << std::endl;
    human->give(card);

    if (human->getTotalValue() > 21) {
        std::cout << human->getName() << " busts!!" << std::endl;
        end(dealer);
        return;
    }

    think();
}

void Game::think() {
    do {
        std::cout << "\nWould you like to hit or stand?" << std::endl;
        std::cout << "\tCurrent Card Value: " << human->getTotalValue() << std::endl << std::endl;
        std::cout << "\tH - Hit and risk busting" << std::endl;
        std::cout << "\tS - Stand your ground" << std::endl << std::endl;
        std::cout << "\tYour Choice [H/S]: ";

        char choice;
        std::cin >> choice;

        if (tolower(choice) == 'h') {
            human->hit();

            if (human->getTotalValue() == 21) {
                end(human);
                break;
            } else if (human->getTotalValue() > 21) {
                std::cout << human->getName() << " busts!!" << std::endl;
                end(dealer);
                break;
            }
        } else {
            break;
        }
    } while (true);
}

void Game::end(Player* ply) {
    std::cout << "\n" << ply->getName() << " wins the game!!" << std::endl;
    std::cout << human->getName() << ": " << human->getTotalValue() << std::endl;
    std::cout << dealer->getName() << ": " << dealer->getTotalValue() << std::endl;
}
