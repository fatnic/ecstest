#ifndef HEALTHCOMPONENT
#define HEALTHCOMPONENT

#include "entity.hpp"

struct Health : Component
{

    float health;
    float max;

    Health(float init_health)
        : health(init_health)
        , max(init_health)
    {}

    Health(float max_health, float init_health)
        : health(init_health)
        , max(max_health)
    {}

    float reduceHealth(float amount)
    {
        health -= amount;
        return health;
    }


    float increaseHealth(float amount)
    {
        health += amount;
        return health;
    }

    void update(sf::Time delta)
    {
        if(health <= 0)
            entity->destroy();
    }
};

#endif // HEALTHCOMPONENT

