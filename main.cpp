#include <iostream>
#include <SFML/Graphics.hpp>
#include "include/Game.h"
#include "include/Button.h"
#include "include/MenuState.h"


int main()
{
    auto *window = new sf::RenderWindow(sf::VideoMode(Theme::MenuWindow::sizeX, Theme::MenuWindow::sizeY), "Hexxagon",
                                        sf::Style::Titlebar | sf::Style::Close);
    auto menu = MenuState(window);
    while (window->isOpen())
    {
        sf::Event event{};
        while (window->pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window->close();
                    break;
                case sf::Event::KeyReleased:
                    switch (event.key.code)
                    {
                        case sf::Keyboard::Up:
                            menu.MoveUp();
                            break;
                        case sf::Keyboard::Down:
                            menu.MoveDown();
                            break;
                        case sf::Keyboard::Return:
                            switch (menu.getSelectedItem().getId())
                            {
                                case 0:
                                    std::cout << "New Game Pressed" << std::endl;
                                    break;
                                case 1:
                                    std::cout << "Load Game Pressed" << std::endl;
                                    break;
                                case 2:
                                    std::cout << "Records Pressed" << std::endl;
                                    break;

                            }
                            break;
                        case sf::Keyboard::Escape:
                            window->close();
                            break;
                    }
                    break;

            }

        }

        menu.Render();
    }


    delete window;

}
