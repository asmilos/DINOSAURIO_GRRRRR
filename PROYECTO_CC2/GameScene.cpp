#include "GameScene.h"

GameScene::GameScene(RenderWindow* window, View * view, const float VIEW_HEIGHT , vector<Player> players, vector<Platform> platforms)
    : window(window) , view(view), VIEW_HEIGHT(VIEW_HEIGHT), players(players), platforms(platforms) {
    deltaTime = 0.0f;
    event = new Event;
    
    imgBackground = new Texture;
    imgBackground->loadFromFile("background.jpeg");

    background = new Sprite(*imgBackground);
    background->setScale({ 1.5,1.5 });

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

        window->display();
    

}

