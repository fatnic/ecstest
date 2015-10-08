#ifndef HEALTHBARCOMPONENT
#define HEALTHBARCOMPONENT

#include "entity.hpp"
#include "positioncomponent.hpp"
#include "healthcomponent.hpp"

struct HealthBar : Component
{
    HealthBar(float offset)
        : _offset(offset)
    {}

    void init()
    {
        float bar_width = 50;
        float bar_height = 6;
        sf::Color bgColour = sf::Color(255,0,0,100);
        sf::Color fgColour = sf::Color(0,120,0);

        cPosition = &entity->getComponent<Position>();
        cHealth = &entity->getComponent<Health>();

        _bgBar = new sf::RectangleShape;
        _bgBar->setSize(sf::Vector2f(bar_width, bar_height));
        _bgBar->setOrigin(_bgBar->getGlobalBounds().width / 2, _bgBar->getGlobalBounds().height / 2);
        _bgBar->setFillColor(bgColour);
        _bgBar->setOutlineColor(sf::Color(120,120,120));
        _bgBar->setOutlineThickness(1.f);

        _healthBar = new sf::RectangleShape;
        _healthBar->setSize(_bgBar->getSize());
        _healthBar->setFillColor(fgColour);
    }

    void update(sf::Time delta)
    {
        float hit_percentage = cHealth->health / cHealth->max * _bgBar->getSize().x;

        if(hit_percentage < 0)
            hit_percentage = 0;

        _healthBar->setSize(sf::Vector2f(hit_percentage, _bgBar->getSize().y));
        _bgBar->setPosition(cPosition->x(), cPosition->y() - _offset);
        _healthBar->setPosition(_bgBar->getGlobalBounds().left + 1, _bgBar->getGlobalBounds().top + 1);
    }

    void draw(sf::RenderTarget *window)
    {
        window->draw(*_bgBar);
        window->draw(*_healthBar);
    }

    sf::RectangleShape* _bgBar;
    sf::RectangleShape* _healthBar;

    Position* cPosition{nullptr};
    Health* cHealth{nullptr};

    float _offset;

};

#endif // HEALTHBARCOMPONENT

