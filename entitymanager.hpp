#ifndef ENTITYMANAGER
#define ENTITYMANAGER

#include "entity.hpp"
#include "algorithm"
#include <singleton.hpp>

struct EntityManager : public Singleton<EntityManager>
{

public:
    std::vector<std::unique_ptr<Entity>> entities;

    static void update(sf::Time delta)
    {
        for(auto& e : getInstance().entities)
            e->update(delta);
    }

    static void draw(sf::RenderTarget* window)
    {
        for(auto& e : getInstance().entities)
            e->draw(window);
    }

    static void refresh()
    {
        getInstance().entities.erase(
                    std::remove_if(std::begin(getInstance().entities), std::end(getInstance().entities),
                                   [](const std::unique_ptr<Entity>& mEntity)
        {
            return !mEntity->isAlive();
        }),
                    std::end(getInstance().entities));

        std::sort(getInstance().entities.begin(), getInstance().entities.end(), sortEntities);
    }

    static Entity& addEntity()
    {
        Entity* e{new Entity{}};
        std::unique_ptr<Entity> uPtr{e};
        getInstance().entities.emplace_back(std::move(uPtr));
        return *e;
    }

private:

    static bool sortEntities(std::unique_ptr<Entity>& e0, std::unique_ptr<Entity>& e1)
    {
        return (e0->zindex < e1->zindex);
    }

};

#endif // ENTITYMANAGER

