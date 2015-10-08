#ifndef ROTATIONCOMPONENT
#define ROTATIONCOMPONENT

#include <math.h>

#include "entity.hpp"
#include "velocitycomponent.hpp"

struct Rotation : Component
{
    Velocity* cVelocity{nullptr};
    float rotation;

    Rotation()
        : rotation(0.f)
    {}

    void init()
    {
        cVelocity = &entity->getComponent<Velocity>();
    }

    void update(sf::Time delta)
    {
        if(cVelocity->velocity.x == 0 && cVelocity->velocity.y == 0) return;

        rotation = (std::atan2(cVelocity->velocity.y, cVelocity->velocity.x) * 180 / M_PI);
    }
};

#endif // ROTATIONCOMPONENT

