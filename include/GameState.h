//
// Created by aliem on 02/05/2024.
//

#ifndef HEXXAGON_GAMESTATE_H
#define HEXXAGON_GAMESTATE_H


#include "State.h"
#include "Board.h"
class GameState : State
{
private:
    sf::RenderWindow *gameWindow;
    std::unordered_map<Player,int>score;
    Board gameBoard;
    Side turn;
public:
    GameState(sf::RenderWindow *gameWindow);

    void EventHandle(sf::Event &event) override;

    void Render() override;

    void Update() override;

    virtual ~GameState();


};


#endif //HEXXAGON_GAMESTATE_H
