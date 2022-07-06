#include <SFML/Graphics.hpp>
#include "iostream"
#include "Player.h"
#include "Platform.h"
#include "GameScene.h"
#include "vector"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 512.0f;

int main()
{
    // creamos nuestra pantalla
    RenderWindow * window = new RenderWindow(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);

    Texture * playerTexture = new Texture;
    playerTexture->loadFromFile("dinosaurio.png");

    // primer vector es el centro, y el resto su tamaño de la vista
    View * view = new View(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    // creamos un un jugador
    Player * player1 = new Player(playerTexture, Vector2u(3, 2), 0.3f, 100.0f, 200.0f);

    // vector de plataformas
    vector<Platform> platforms;

    platforms.push_back(Platform(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platform(nullptr, Vector2f(400.0f, 200.0f), Vector2f(500.0f, 0.0f)));
    platforms.push_back(Platform(nullptr, Vector2f(1000.0f, 200.0f), Vector2f(500.0f, 500.0f)));

    GameScene* scene = new GameScene(window,view,VIEW_HEIGHT,player1,platforms);
    scene->gameloop();

    return 0;
}