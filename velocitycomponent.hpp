#ifndef VELOCITYCOMPONENT
#define VELOCITYCOMPONENT

#include "entity.hpp"
#include "spritecomponent.hpp"
#include <SFML/Graphics.hpp>

struct Velocity : Component
{

    Velocity()
        : velocity()
    {}

    Velocity(float speed)
        : velocity()
        , speed(speed)
    {}

    void init()
    {
        cPosition = &entity->getComponent<Position>();
    }

    void update(sf::Time delta)
    {
        cPosition->position += velocity * delta.asSeconds() * speed;
    }

    sf::Vector2f velocity;
    float speed{1.f};
    Position* cPosition{nullptr};
};

#endif // VELOCITYCOMPONENT

