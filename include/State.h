//
// Created by aliem on 02/05/2024.
//

#ifndef HEXXAGON_STATE_H
#define HEXXAGON_STATE_H
#include <SFML/Graphics.hpp>

class State{
public:
    virtual void EventHandle(sf::Event &event) =0;
    virtual void Render() = 0;
    virtual void Update() = 0;

};
#endif //HEXXAGON_STATE_H
