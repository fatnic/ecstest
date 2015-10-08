#ifndef SPRITECOMPONENT
#define SPRITECOMPONENT

#include "entity.hpp"
#include "assetmanager.hpp"
#include "positioncomponent.hpp"
#include "rotationcomponent.hpp"

struct Sprite : Component
{
    sf::Sprite sprite;
    sf::Texture _texture;

    Position* cPosition{nullptr};
    Rotation* cRotation{nullptr};

    sf::Vector2f _size;


    Sprite(sf::Texture& texture)
        : _texture(texture)
        , _size()
    {}

    Sprite(sf::Texture& texture, sf::Vector2f origin)
        : _texture(texture)
        , _size(origin)
    {}

    void init()
    {
        if(entity->hasComponent<Position>())
            cPosition = &entity->getComponent<Position>();

        if(entity->hasComponent<Rotation>())
            cRotation = &entity->getComponent<Rotation>();

        sprite.setTexture(_texture);

        if(_size != sf::Vector2f(0,0))
            sprite.setOrigin(_size.x / 2, _size.y / 2);
        else
            sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);

        if(cPosition != nullptr)
            sprite.setPosition(cPosition->position);

    }

    void update(sf::Time delta)
    {
        if(cPosition != nullptr)
            sprite.setPosition(cPosition->position);

        if(cRotation != nullptr)
            sprite.setRotation(cRotation->rotation);
    }

    void draw(sf::RenderTarget* window)
    {
        window->draw(sprite);
    }
};

#endif // SPRITECOMPONENT

