#ifndef SPRITECOMPONENT
#define SPRITECOMPONENT

#include "entity.hpp"
#include "positioncomponent.hpp"
#include "assetmanager.hpp"

struct Sprite : Component
{
    Position* cPosition{nullptr};
    sf::Sprite sprite;
    sf::Texture _texture;

    Sprite(sf::Texture& texture)
        : _texture(texture)
    {}

    void init()
    {
        cPosition = &entity->getComponent<Position>();

        sprite.setTexture(_texture);
        sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
        sprite.setPosition(cPosition->position);
    }

    void update(float mFT)
    {
        sprite.setPosition(cPosition->position);
    }

    void draw(sf::RenderTarget* window)
    {
        window->draw(sprite);
    }
};

#endif // SPRITECOMPONENT

