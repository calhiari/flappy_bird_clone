#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Flappy Bird Clone");
    sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
    // player.setFillColor(sf::Color::Red);
    player.setOrigin(206.0, 206.0);       // set origin of the player

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::TextEntered:
                if (event.text.unicode < 128)
                    std::cout << static_cast<char>(event.text.unicode);
                break;

            default:
                break;
            }
        }

        /*if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            player.setPosition(sf::Vector2f(mousePos));
        }*/

        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}