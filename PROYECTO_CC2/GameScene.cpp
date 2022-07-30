#include <iostream>
#include "GameScene.h"

GameScene::GameScene(RenderWindow* window, View * view, const float VIEW_HEIGHT , vector<Player> players, vector<Platform> platforms)
    : Scene(window), view(view), VIEW_HEIGHT(VIEW_HEIGHT), players(players), platforms(platforms) {
    deltaTime = 0.0f;
    
    imgBackground = new Texture;
    imgBackground->loadFromFile("Images/background.jpeg");

    background = new Sprite(*imgBackground);
    background->setScale({ 1.5,1.5 });

    clockTimer = new Clock;
    timeTimer = new Time;

    totalTime = 30;
    textTimer = new Text;
    textTimer->setString(to_string(totalTime));

}


void GameScene::ResizeView()
{
    float aspectRatio = float(window->getSize().x) / float(window->getSize().y);
    view->setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

void GameScene::events() {
    while (window->pollEvent(*event))
    {
        switch (event->type)
        {
        case Event::Closed:
            window->close();
            break;
        case Event::Resized:
            ResizeView();
            break;

        }
    }
}


void GameScene::loop() {

        deltaTime = clock.restart().asSeconds();
        
        events();

        for (Player& player : players) {
            player.Update(deltaTime);
        }


        Vector2f direction;

        for (Platform& platform : platforms) {
            for (Player& player : players)
                if (platform.GetCollider().CheckCollider(player.GetCollider(), direction, 1.0f))
                {
                    player.OnCollision(direction);
                }
        }


        view->setCenter(players.at(0).GetPosition());

        window->clear(Color(100, 100, 100));
        window->draw(*background);

        //window->setView(*view);//seguir camara de jugador


        // jugadores
        for (Player& player : players) {
            player.Draw(*window);
        }

        // plataformas
        for (Platform& platform : platforms)
            platform.Draw(*window);

        // tiempo
        *timeTimer = clockTimer->getElapsedTime();
        std::cout << totalTime - (int)timeTimer->asSeconds() << std::endl;
        window->draw(*textTimer);

        window->display();
}

