#include <SFML/Graphics.hpp>

#include "entitymanager.hpp"
#include "assetmanager.hpp"

#include "spritecomponent.hpp"
#include "positioncomponent.hpp"
#include "animatedcomponent.hpp"
#include "velocitycomponent.hpp"
#include "attachtomousecomponent.hpp"
#include "keyboardcontrolcomponent.hpp"
#include "rotationcomponent.hpp"
#include "healthcomponent.hpp"
#include "healthbarcomponent.hpp"

const int screen_x = 1120;
const int screen_y = screen_x / 16*9;

int main()
{
    sf::RenderWindow window(sf::VideoMode(screen_x, screen_y), "GameWindow");
    window.setMouseCursorVisible(false);

    new EntityManager;
    new AssetManager;

    std::vector<Entity*> baddies;

    sf::Clock clock;

    Entity& player(EntityManager::addEntity());
    player.addComponent<Position>(sf::Vector2f(200,200));
    player.addComponent<Velocity>(80.f);
    player.addComponent<KeyboardControl>();
    player.addComponent<Rotation>();
    player.addComponent<Sprite>(AssetManager::getTexture("assets/player.png"));
    player.addComponent<Health>(100);
    player.addComponent<HealthBar>(50);
    player.addComponent<AttachToMouse>(window);

    Entity& coin(EntityManager::addEntity());
    coin.addComponent<Position>(sf::Vector2f(400,300));
    coin.addComponent<Sprite>(AssetManager::getTexture("assets/coin.png"));
    coin.addComponent<Animated>();
    coin.addComponent<Health>(100, 90);
    coin.addComponent<HealthBar>(30);
    coin.zindex = 10;

    Animator::Animation& coin_spin = coin.getComponent<Animated>().createAnimation("spinning", "assets/coin.png", sf::Vector2i(32,32), sf::seconds(.75), true);
    coin_spin.addFrames(sf::Vector2i(0,0), 8);

    baddies.push_back(&coin);

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
            player.getComponent<Health>().reduceHealth(1);

        sf::Time delta = clock.restart();

        window.clear(sf::Color(64,64,64));

        EntityManager::refresh();
        EntityManager::update(delta);
        EntityManager::draw(&window);

        window.display();
    }

    delete AssetManager::getInstancePtr();
    delete EntityManager::getInstancePtr();

}
