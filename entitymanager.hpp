#ifndef ENTITYMANAGER
#define ENTITYMANAGER

#include "entity.hpp"
#include "algorithm"

struct EntityManager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void update(sf::Time delta) { for(auto& e : entities) e->update(delta); }
    void draw(sf::RenderTarget* window)
    {
        for(auto& e : entities)
            e->draw(window);
    }

    void refresh()
    {
        entities.erase(
                    std::remove_if(std::begin(entities), std::end(entities),
                                   [](const std::unique_ptr<Entity>& mEntity)
        {
            return !mEntity->isAlive();
        }),
                    std::end(entities));

        std::sort(entities.begin(), entities.end(), sortEntities);
    }

    Entity& addEntity()
    {
        Entity* e{new Entity{}};
        std::unique_ptr<Entity> uPtr{e};
        entities.emplace_back(std::move(uPtr));
        return *e;
    }

    static bool sortEntities(std::unique_ptr<Entity>& e0, std::unique_ptr<Entity>& e1)
    {
        return (e0->zindex < e1->zindex);
    }

};

#endif // ENTITYMANAGER

