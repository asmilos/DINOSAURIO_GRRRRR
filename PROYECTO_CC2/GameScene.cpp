#include "GameScene.h"

GameScene::GameScene(RenderWindow* window, View * view, const float VIEW_HEIGHT , Player *& player, vector<Platform> platforms)
    : window(window) , view(view), VIEW_HEIGHT(VIEW_HEIGHT), player(player), platforms(platforms) {
    deltaTime = 0.0f;
    event = new Event;
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


void GameScene::gameloop() {

    while (window->isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        
        events();

        player->Update(deltaTime);

        Vector2f direction;

        for (Platform& platform : platforms)
            if (platform.GetCollider().CheckCollider(player->GetCollider(), direction, 1.0f))
                player->OnCollision(direction);


        view->setCenter(player->GetPosition());


        window->clear(Color(100, 100, 100));
        window->setView(*view);


        player->Draw(*window);

        for (Platform& platform : platforms)
            platform.Draw(*window);

        window->display();
    }

}

