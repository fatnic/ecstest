#ifndef KEYBOARDCONTROLCOMPONENT
#define KEYBOARDCONTROLCOMPONENT

#include "entity.hpp"
#include "velocitycomponent.hpp"

struct KeyboardControl : Component
{
    Velocity* cVelocity{nullptr};

    KeyboardControl(){}

    void init()
    {
        cVelocity = &entity->getComponent<Velocity>();
    }

    void update(sf::Time delta)
    {
        cVelocity->velocity.x = 0;
        cVelocity->velocity.y = 0;

        bool movingUp    = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
        bool movingDown  = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
        bool movingLeft  = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
        bool movingRight = sf::Keyboard::isKeyPressed(sf::Keyboard::D);

        if(movingUp)
            cVelocity->velocity.y = -1;
        if(movingDown)
            cVelocity->velocity.y = 1;
        if(movingLeft)
            cVelocity->velocity.x = -1;
        if(movingRight)
            cVelocity->velocity.x = 1;
    }
};

#endif // KEYBOARDCONTROLCOMPONENT

