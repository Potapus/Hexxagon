//
// Created by aliem on 02/05/2024.
//

#include "../include/MenuState.h"
#include <fmt/ranges.h>
#include <fmt/core.h>

MenuState::MenuState(sf::RenderWindow *gameWindow) : menuWindow(gameWindow)
{
    std::filesystem::path current_path = std::filesystem::current_path();
    std::filesystem::path relative_path = current_path / "fonts" / "VeraMono.ttf";

    //std::cout << relative_path;
    // fonts dir is in the cmake debug dir.

    if (!Theme::MenuWindow::font.loadFromFile(relative_path.string()))
        std::cerr << "CANT LOAD FONT" << std::endl;

    text.setFont(Theme::MenuWindow::font);
    text.setString("Hexxagon");
    text.setCharacterSize(48);
    text.setPosition(Theme::MenuWindow::sizeX / 2 - 100, Theme::MenuWindow::sizeY / 8);

    InitAllButtons();

    selectedButton = 0;
}

void MenuState::EventHandle(sf::Event &event)
{
    sf::Event menuEvents;
    while (menuWindow->pollEvent(menuEvents))
    {
        switch (menuEvents.type)
        {
            case sf::Event::Closed:
                menuWindow->close();
                break;
        }
    }
}

void MenuState::Render()
{
    menuWindow->clear();
    for (Button &b: buttons)
    {
        menuWindow->draw(text);
        menuWindow->draw(b.getShape());
        menuWindow->draw(b.getText());
    }
    menuWindow->display();
}

void MenuState::Update()
{

}

void MenuState::InitButton(const std::string &buttonTitle, Button &newButton, float xPos, float yPos)
{

    newButton.getText().setString(buttonTitle);
    newButton.getText().setFont(Theme::MenuWindow::font);

    const float posButtonX = xPos - newButton.getShape().getSize().x / 2.0f;
    const float posButtonY = yPos - newButton.getShape().getSize().y / 2.0f;
    newButton.getShape().setPosition(posButtonX, posButtonY);

    sf::FloatRect textRect = newButton.getText().getLocalBounds();
    const float xPosText = posButtonX + (newButton.getShape().getSize().x - textRect.width) / 2.0f;
    const float yPosText = posButtonY + (newButton.getShape().getSize().y - textRect.height) / 2.0f;
    newButton.getText().setPosition(xPosText, yPosText);
    newButton.SetId();
}


void MenuState::InitAllButtons()
{
    const float buttonSpacing = 20.0f;
    float currentY = menuWindow->getSize().y / 2.0f;
    float currentX = menuWindow->getSize().x / 2.0f;

    auto records = Button(), newGame = Button(), loadGame = Button();

    InitButton("New Game", newGame, currentX, currentY);
    currentY += newGame.getShape().getSize().y + buttonSpacing;
    buttons.push_back(newGame);


    InitButton("Load Game", loadGame, currentX, currentY);
    currentY += loadGame.getShape().getSize().y + buttonSpacing;
    buttons.push_back(loadGame);


    InitButton("Records", records, currentX, currentY);
    buttons.push_back(records);
}

MenuState::~MenuState()
{
    delete menuWindow;
}

void MenuState::MoveDown()
{
    if (selectedButton < 2)
    {
        buttons[selectedButton].getText().setFillColor(sf::Color::Red);
        selectedButton++;
        buttons[selectedButton].getText().setFillColor(sf::Color::White);
    }
}

void MenuState::MoveUp()
{
    if (selectedButton > 0)
    {
        buttons[selectedButton].getText().setFillColor(sf::Color::Red);
        selectedButton--;
        buttons[selectedButton].getText().setFillColor(sf::Color::White);
    }
}

Button MenuState::getSelectedItem()
{
    return buttons[selectedButton];
}


