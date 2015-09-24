#include "animator.hpp"
#include "assetmanager.hpp"

Animator::Animator(sf::Sprite &sprite)
    : _sprite(sprite)
    , _currentTime()
    , _currentAnimation(nullptr)
{}

Animator::Animation &Animator::createAnimation(const std::string &name, const std::string &texturename, const sf::Time &duration, bool looping)
{
    _animations.push_back(Animator::Animation(name, texturename, duration, looping));

    if(_currentAnimation == nullptr)
        switchAnimation(&_animations.back());

    return _animations.back();
}

void Animator::update(const sf::Time &delta)
{
    if(_currentAnimation == nullptr)
        return;

    _currentTime += delta;

    float scaledTime = _currentTime.asSeconds() / _currentAnimation->_duration.asSeconds();
    int numFrames = _currentAnimation->_frames.size();
    int currentFrame = static_cast<int>(scaledTime * numFrames);

    if(_currentAnimation->_looping)
        currentFrame %= numFrames;
    else if(currentFrame >= numFrames)
        currentFrame = numFrames - 1;

    _sprite.setTextureRect(_currentAnimation->_frames[currentFrame]);
}

bool Animator::switchAnimation(const std::string &name)
{
    auto animation = findAnimation(name);
    if(animation != nullptr)
    {
        switchAnimation(animation);
        return true;
    }
    return false;
}

std::string Animator::getCurrentAnimationName() const
{
    if(_currentAnimation != nullptr)
        return _currentAnimation->_name;
    return "";
}

Animator::Animation *Animator::findAnimation(const std::string &name)
{
    for(auto it = _animations.begin(); it != _animations.end(); it++)
    {
        if(it->_name == name)
            return &*it;
    }
    return nullptr;
}

void Animator::switchAnimation(Animator::Animation *animation)
{
    if(animation != nullptr) {}
        _sprite.setTexture(AssetManager::getTexture(animation->_texturename));

    _currentAnimation = animation;
    _currentTime = sf::Time::Zero;
}