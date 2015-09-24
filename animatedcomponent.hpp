#ifndef ANIMATEDCOMPONENT_HPP
#define ANIMATEDCOMPONENT_HPP

#include "entity.hpp"
#include "animator.hpp"
#include "spritecomponent.hpp"

struct Animated : Component
{

    Animated(sf::Sprite& sprite)
        : _animator(sprite)
    {
    }

    void init()
    {
    }

    void update(sf::Time delta)
    {
        _animator.update(delta);
    }

    Animator::Animation& createAnimation(std::string const& name, std::string const& texturename, sf::Time const& duration, bool looping)
    {
       return _animator.createAnimation(name, texturename, duration, looping);
    }

private:
    Animator _animator;

};

#endif // ANIMATEDCOMPONENT_HPP
