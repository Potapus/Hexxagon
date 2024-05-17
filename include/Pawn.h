//
// Created by aliem on 17/05/2024.
//

#ifndef HEXXAGON_PAWN_H
#define HEXXAGON_PAWN_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Side.h"
class Pawn : public sf::CircleShape
{
private:
    float radius;
    sf::Color color;
    sf::Color outlineColor;
    float outlineThickness;
    Side side;
public:
    Pawn(Side& side);
    void draw();
};
#endif //HEXXAGON_PAWN_H
