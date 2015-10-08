#ifndef GRAVITYCOMPONENT
#define GRAVITYCOMPONENT

#include "entity.hpp"
#include "velocitycomponent.hpp"

struct Gravity : Component
{
    float strength;
    Velocity* cVelocity{nullptr};

    Gravity()
        : strength(10.f)
    {}

    Gravity(float _strength)
        : strength(_strength)
    {}

    void init()
    {
        cVelocity = &entity->getComponent<Velocity>();
    }

    void update(sf::Time delta)
    {
        cVelocity->velocity.y += strength * delta.asSeconds();
    }

};

#endif // GRAVITYCOMPONENT

