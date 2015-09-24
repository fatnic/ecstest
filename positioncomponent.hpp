#ifndef POSITIONCOMPONENT
#define POSITIONCOMPONENT

#include "entity.hpp"
#include "spritecomponent.hpp"

struct Position : Component
{
    sf::Vector2f position;

    Position(sf::Vector2f initialPosition) : position(initialPosition) {}

    void setPosition(sf::Vector2f _position)
    {
        position = _position;
    }

};

#endif // POSITIONCOMPONENT

