//
// Created by aliem on 17/05/2024.
//
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <math.h>

class HEX : public sf::CircleShape {
public:
    HEX(float radius) : sf::CircleShape(radius, 6) {
        this->setFillColor(sf::Color::Magenta);
        this->setOutlineColor(sf::Color::Blue);
        this->setOutlineThickness(5);
        this->setRotation(90);
    }
};

void drawHexGrid(sf::RenderWindow& window, const std::vector<HEX>& hexagons) {
    window.clear();
    for (const auto& hex : hexagons) {
        window.draw(hex);
    }
    window.display();
}

std::vector<HEX> generateHexagons(float radius, int layers, sf::Vector2f center, const std::vector<sf::Vector2i>& specialHexes) {
    std::vector<HEX> hexagons;
    const float hexHeight = radius * sqrt(3);
    const float hexWidth = 2 * radius;
    const float vertSpacing = hexHeight;  // Increase vertical spacing
    const float horizSpacing = hexWidth * 0.75f; // Increase horizontal spacing

    auto isSpecialHex = [&specialHexes](int q, int r) {
        return std::find(specialHexes.begin(), specialHexes.end(), sf::Vector2i(q, r)) != specialHexes.end();
    };

    for (int r = -layers + 1; r < layers; ++r)// -4 -3 -2 -1 0 1 2 3 4 < 5
    {
        int q1 = std::max(-layers + 1, -r - layers + 1); //(-4,-8) (-3,-7) (-2,-6)
        int q2 = std::min(layers - 1, -r + layers - 1);
        for (int q = q1; q <= q2; ++q) {
            HEX hex(radius);
            float x = center.x + (q * horizSpacing);
            float y = center.y + (r * vertSpacing + q * vertSpacing / 2);
            hex.setPosition(x, y);

            if (isSpecialHex(q, r)) {
                hex.setFillColor(sf::Color::Black);
            }

            hexagons.push_back(hex);
        }
    }

    return hexagons;
}

//std::unordered_map<Pawn,location>;

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Hexagon Grid");

    const float radius = 30;
    const int layers = 5; // This creates a hexagon with a side length of 5
    const sf::Vector2f center(window.getSize().x/2, window.getSize().y/2-50);
    const std::vector<sf::Vector2i> specialHexes = {
            {0, -1},
            {-1, 1},
            {1, 0},
    };

    std::vector<HEX> hexagons;
    for (int i = 1; i <= layers; ++i) {
        hexagons = generateHexagons(radius, i, center, specialHexes);
        drawHexGrid(window, hexagons);
        sf::sleep(sf::milliseconds(1000)); // Adjust the delay between layers (in milliseconds)
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }

    return 0;
}
