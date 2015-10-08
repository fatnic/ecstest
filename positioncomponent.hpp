#ifndef POSITIONCOMPONENT
#define POSITIONCOMPONENT

#include <iostream>
#include "entity.hpp"
#include "spritecomponent.hpp"

struct Position : Component
{
    sf::Vector2f position;

    Position(sf::Vector2f initialPosition) : position(initialPosition) {}

    float x() { return position.x; }
    float y() { return position.y; }

    void update(sf::Time delta)
    {
    }
};

#endif // POSITIONCOMPONENT

