//
// Created by aliem on 10/05/2024.
//

#ifndef HEXXAGON_GRAPHICS_H
#define HEXXAGON_GRAPHICS_H

#endif //HEXXAGON_GRAPHICS_H
#include "SFML/Graphics.hpp"

namespace Theme
{

    class MenuWindow
    {
    public:
        inline static const sf::Color background = sf::Color::Black;
        inline static const sf::Color title = sf::Color::Blue;

        inline static const int sizeX = 800;
        inline static const int sizeY = 600;

        inline static sf::Font font;
    };

    class Button
    {
    public:
        inline static const sf::Color background = sf::Color(0x40E0D0);
        inline static const sf::Color text = sf::Color::Red;
        inline static const sf::Vector2f size = {Theme::MenuWindow::sizeX * 3 / 10, Theme::MenuWindow::sizeY / 12};
    };
}