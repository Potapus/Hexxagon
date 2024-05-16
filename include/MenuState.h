//
// Created by aliem on 02/05/2024.
//


#ifndef HEXXAGON_MENUSTATE_H
#define HEXXAGON_MENUSTATE_H

#include "State.h"
#include "Button.h"
#include <fmt/ranges.h>
#include <fmt/core.h>
#include <filesystem>

class MenuState : State
{
private:
    sf::RenderWindow *menuWindow;
    sf::Text text;
    std::vector<Button> buttons;
    Button button;
    int selectedButton;

public:
    MenuState(sf::RenderWindow* gameWindow);

    static void InitButton(const std::string &buttonTitle, Button &menuButton, float xPos, float yPos);

    void InitAllButtons();

    void EventHandle(sf::Event &event) override;

    void Render() override;

    void Update() override;

    void MoveUp();

    void MoveDown();

    Button getSelectedItem();

    virtual ~MenuState();
};


#endif //HEXXAGON_MENUSTATE_H
