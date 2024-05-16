//
// Created by aliem on 07/05/2024.
//

#ifndef HEXXAGON_GAME_H
#define HEXXAGON_GAME_H

#include "State.h"
#include "Board.h"

// Main loop for all states.
class Game
{
private:
    sf::RenderWindow* gameWindow;
    sf::VideoMode videoMode;
    void init();
public:
    Game();

    bool gameOver() const;
    void pollEvents();
    void update();
    void render();
};


#endif //HEXXAGON_GAME_H
