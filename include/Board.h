//
// Created by aliem on 02/05/2024.
//

#ifndef HEXXAGON_BOARD_H
#define HEXXAGON_BOARD_H

#include <unordered_map>
#include "Side.h"
#include "Player.h"


constexpr auto EMPTY = Side::EMPTY;
constexpr auto NOT_P = Side::NOT_P;
constexpr auto RED = Side::RED;
constexpr auto WHITE = Side::WHITE;


class Board
{
private:
    Player player1;
    Player player2;

    std::vector<std::vector<Side>> map =
            {               {RED, EMPTY, EMPTY, EMPTY, WHITE},
                         {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                      {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                  {EMPTY, EMPTY, EMPTY, EMPTY, NOT_P, EMPTY, EMPTY, EMPTY},
               {WHITE, EMPTY, EMPTY, NOT_P, EMPTY, EMPTY, EMPTY, EMPTY, RED},
                  {EMPTY, EMPTY, EMPTY, EMPTY, NOT_P, EMPTY, EMPTY, EMPTY},
                      {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                         {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
                              {RED, EMPTY, EMPTY, EMPTY, WHITE}
            };
public:
    Board();
    static void InitBoard();
    void EventHandle(sf::Event& evet);
    void Render();
    void Update();
    void drawBoard(sf::RenderWindow *window);
};


#endif //HEXXAGON_BOARD_H
