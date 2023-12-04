#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    sf::RenderWindow window(sf::VideoMode(512, 512), "Flappy bird clone");
    sf::RectangleShape player(sf::Vector2f(100.f, 100.f));
    player.setFillColor(sf::Color::Red);

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


        window.clear();
        window.draw(player);
        window.display();
    }

    return 0;
}