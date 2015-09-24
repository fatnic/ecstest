#ifndef ATTACHTOMOUSECOMPONENT
#define ATTACHTOMOUSECOMPONENT

#include <iostream>
#include "entity.hpp"
#include "positioncomponent.hpp"

struct AttachToMouse : Component
{
    AttachToMouse(sf::RenderWindow& window)
    : _window(window)
    {}

    void update(sf::Time delta)
    {
        int x = sf::Mouse::getPosition(_window).x;
        int y = sf::Mouse::getPosition(_window).y;

        entity->getComponent<Sprite>().sprite.setPosition(sf::Vector2f(x,y));
    }

    sf::RenderWindow& _window;

};

#endif // ATTACHTOMOUSECOMPONENT

