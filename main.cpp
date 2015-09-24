#include <SFML/Graphics.hpp>

#include "entitymanager.hpp"
#include "assetmanager.hpp"

#include "spritecomponent.hpp"
#include "positioncomponent.hpp"
#include "animatedcomponent.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "GameWindow");

    EntityManager em;
    AssetManager am;

    sf::Clock clock;

    Entity& coin(em.addEntity());
    coin.addComponent<Position>(sf::Vector2f(200,200));
    coin.addComponent<Sprite>(AssetManager::getTexture("assets/coin.png"));
    coin.addComponent<Animated>(coin.getComponent<Sprite>().sprite);

    auto& coin_spin = coin.getComponent<Animated>().createAnimation("spinning", "assets/coin.png", sf::seconds(.5), true);
    coin_spin.addFrames(sf::Vector2i(0,0), sf::Vector2i(32,32), 8);

    // TODO: Move origin to center of animation frame

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time delta = clock.restart();

        window.clear();

        em.refresh();
        em.update(delta);
        em.draw(&window);

        window.display();
    }

}
