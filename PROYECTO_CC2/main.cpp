#include <SFML/Graphics.hpp>
#include "iostream"
#include "Player.h"
#include "Source.h"
#include "Platform.h"
#include "main.h"
#include "vector"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 512.0f;
void ResizeView(const RenderWindow& window, View& view) 
{
    float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
    view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}
int main()
{

    RenderWindow window(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);
    Texture playerTexture;
    View view(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
    playerTexture.loadFromFile("dinosaurio.png");
    Player player(&playerTexture, Vector2u(3, 2), 0.3f, 100.0f, 200.0f);

    vector<Platform> platforms;

    platforms.push_back(Platform(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platform(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 0.0f)));
    platforms.push_back(Platform(nullptr, Vector2f(1000.0f, 200.0f), Vector2f(500.0f, 500.0f)));

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
            case Event::Resized:
                ResizeView(window, view);
                break;

            }
        }
        player.Update(deltaTime);

        Vector2f direction;

        for (Platform& platform : platforms)
            if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
                player.OnCollision(direction);
        

        view.setCenter(player.GetPosition());


        window.clear(Color(100, 100, 100));
        window.setView(view);


        player.Draw(window);
        
        for (Platform& platform : platforms)
        platform.Draw(window);

        window.display();
    }
    return 0;
}