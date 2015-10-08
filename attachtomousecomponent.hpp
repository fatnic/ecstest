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
        if(active)
        {
            int x = sf::Mouse::getPosition(_window).x;
            int y = sf::Mouse::getPosition(_window).y;

            entity->getComponent<Position>().position = sf::Vector2f(x,y);
        }
    }

    sf::RenderWindow& _window;
    bool active = true;
};

#endif // ATTACHTOMOUSECOMPONENT

