#ifndef SPRITECOMPONENT
#define SPRITECOMPONENT

#include "entity.hpp"
#include "assetmanager.hpp"

struct Sprite : Component
{
    sf::Sprite sprite;
    sf::Texture _texture;
    sf::Vector2f _position;
    sf::Vector2f _size;

    Sprite(sf::Texture& texture, sf::Vector2f position)
        : _texture(texture)
        , _position(position)
        , _size()
    {}

    Sprite(sf::Texture& texture, sf::Vector2f position, sf::Vector2f origin)
        : _texture(texture)
        , _position(position)
        , _size(origin)
    {}

    void init()
    {
        sprite.setTexture(_texture);
        if(_size != sf::Vector2f(0,0))
        {
            sprite.setOrigin(_size.x / 2, _size.y / 2);
        }
        else
        {
            sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
        }
        sprite.setPosition(_position);
    }

    void update(float mFT)
    {}

    void draw(sf::RenderTarget* window)
    {
        window->draw(sprite);
    }
};

#endif // SPRITECOMPONENT

