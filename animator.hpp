#ifndef ANIMATOR_HPP
#define ANIMATOR_HPP

#include <vector>
#include <list>
#include <SFML/Graphics.hpp>

class Animator
{
public:

    struct Animation
    {
    public:
        std::string _name;
        std::string _texturename;
        std::vector<sf::IntRect> _frames;
        sf::Time _duration;
        bool _looping;

        Animation(std::string const& name, std::string const& texturename, sf::Time const& duration, bool looping)
            : _name(name)
            , _texturename(texturename)
            , _duration(duration)
            , _looping(looping)
        {}

        void addFrames(sf::Vector2i const& startFrom, sf::Vector2i const& frameSize, unsigned int frames)
        {
            sf::Vector2i current = startFrom;
            for(unsigned int i = 0; i < frames; i++)
            {
                _frames.push_back(sf::IntRect(current.x, current.y, frameSize.x, frameSize.y));
                current.x += frameSize.x;
            }
        }
    };

    Animator(sf::Sprite& sprite);
    Animator::Animation& createAnimation(std::string const& name, std::string const& texturename, sf::Time const& duration, bool looping);
    void update(sf::Time const& delta);
    bool switchAnimation(std::string const& name);
    std::string getCurrentAnimationName() const;

    Animator::Animation* currentAnimation;
private:
    Animator::Animation* findAnimation(std::string const& name);
    void switchAnimation(Animator::Animation* animation);

    sf::Sprite& _sprite;
    sf::Time _currentTime;
    std::list<Animator::Animation> _animations;
};

#endif // ANIMATOR_HPP
