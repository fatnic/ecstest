#ifndef ANIMATEDCOMPONENT_HPP
#define ANIMATEDCOMPONENT_HPP

#include "entity.hpp"
#include "animator.hpp"
#include "spritecomponent.hpp"

struct Animated : Component
{

    Animated()
    {
    }

    void init()
    {
        _animator = new Animator(entity->getComponent<Sprite>().sprite);
    }

    void update(sf::Time delta)
    {
        _animator->update(delta);
    }

    Animator::Animation& createAnimation(std::string const& name, std::string const& texturename, sf::Vector2i framesize, sf::Time const& duration, bool looping)
    {
        Animator::Animation& anim = _animator->createAnimation(name, texturename, framesize, duration, looping);
        entity->getComponent<Sprite>().sprite.setOrigin(anim.frameSize.x / 2, anim.frameSize.y / 2);
        return anim;
    }

    bool switchAnimation(std::string const& name)
    {
        return _animator->switchAnimation(name);
    }

private:
    Animator* _animator;

};

#endif // ANIMATEDCOMPONENT_HPP
