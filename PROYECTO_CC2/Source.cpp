#include <SFML/Graphics.hpp>
#include "iostream"
#include "Player.h"
#include "Source.h"

using namespace sf;

int main()
{

    RenderWindow window(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);
    Texture playerTexture;
    
    playerTexture.loadFromFile("Sprite.png");
    Player player(&playerTexture, Vector2u(1, 1), 0.3f, 100.0f);

    float deltaTime = 0.0f;
    Clock clock;

  
    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                window.close();
                break;

            }
        }
        player.Update(deltaTime);


        window.clear(Color(150, 150, 150));
        player.Draw(window);
        window.display();
    }
    return 0;
}