//
// Created by aliem on 02/05/2024.
//

#include "../include/Button.h"

int Button::counter = 0;

Button::Button()
{
    shape.setSize(Theme::Button::size);
    shape.setFillColor(Theme::Button::background);
    text.setFillColor(Theme::Button::text);
}

sf::Vector2f Button::getPosition()
{
    return shape.getPosition();
}

int Button::getId()
{
    return id;
}

sf::Text &Button::getText()
{
    return text;
}

sf::RectangleShape &Button::getShape()
{
    return shape;
}

void Button::SetId()
{
    this->id=counter++;
}


