//
// Created by aliem on 07/05/2024.
//

#ifndef HEXXAGON_PLAYER_H
#define HEXXAGON_PLAYER_H
#include "Side.h"
#include <SFML/Graphics.hpp>

class Player
{
private:
    Side side;
    sf::Vector2<int> windowPos;
    std::pair<int,int> tilePos;
    sf::CircleShape pawnShape;
    bool turn;
public:
    void move();
    bool isTurn() const;
    void drawPawn();
};


#endif //HEXXAGON_PLAYER_H
