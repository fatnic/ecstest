#ifndef ENTITY
#define ENTITY

// Completely copied from

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include <cassert>
#include <type_traits>

#include <SFML/Graphics.hpp>

struct Component;
class Entity;

using ComponentID = std::size_t;

namespace Internal
{
inline ComponentID getUniqueComponentID() noexcept
{
    static ComponentID lastID{0u};
    return lastID++;
}
}

template<typename T> inline ComponentID getComponentTypeID() noexcept
{
    static_assert(std::is_base_of<Component, T>::value,
                  "T must inherit from Component");

    static ComponentID typeID{Internal::getUniqueComponentID()};
    return typeID;
}

constexpr std::size_t maxComponents{32};

using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

struct Component
{
    Entity* entity;
    virtual void init() { }
    virtual void update(sf::Time delta) { }
    virtual void draw(sf::RenderTarget* window) { }

    virtual ~Component() { }
};

class Entity
{
private:
    bool alive{true};
    std::vector<std::unique_ptr<Component>> components;

    ComponentArray componentArray;
    ComponentBitset componentBitset;

public:
    int zindex{100};
    void update(sf::Time delta)           { for(auto& c : components) c->update(delta); }
    void draw(sf::RenderTarget* window)   { for(auto& c : components) c->draw(window); }

    bool isAlive() const 	{ return alive; }
    void destroy() 			{ alive = false; }

    template<typename T> bool hasComponent() const
    {
        return componentBitset[getComponentTypeID<T>()];
    }

    template<typename T, typename... TArgs>
    T& addComponent(TArgs&&... mArgs)
    {

        assert(!hasComponent<T>());

        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;

        c->init();

        return *c;
    }

    template<typename T> T& getComponent() const
    {
        assert(hasComponent<T>());
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }

    bool operator < (const Entity& e)
    {
        std::cout << "Sorting " << zindex << " and " << e.zindex << std::endl;
        return zindex < e.zindex;
    }
};




#endif // ENTITY

