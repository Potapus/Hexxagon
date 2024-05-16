//
// Created by aliem on 02/05/2024.
//

#ifndef HEXXAGON_BUTTON_H
#define HEXXAGON_BUTTON_H

#include "SFML/Graphics.hpp"
#include "Graphics.h"
#include <string>
#include <iostream>

class Button
{
private:
    int id;
    sf::Text text;
    sf::RectangleShape shape;
public:
    Button();

    sf::Vector2f getPosition();

    static int counter;

    int getId();

    sf::Text &getText();

    sf::RectangleShape &getShape();

    void SetId();
};



#endif //HEXXAGON_BUTTON_H
