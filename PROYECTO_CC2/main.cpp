#include <SFML/Graphics.hpp>
#include "iostream"
#include "Player.h"
#include "Platform.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "vector"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 512.0f;

GameScene * createGame(RenderWindow * window, View * view, bool multiplayer);

int main()
{
    // creamos nuestra pantalla
    RenderWindow* window = new RenderWindow(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);
    // primer vector es el centro, y el resto su tamaño de la vista
    View* view = new View(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    int opc = 0;
    bool gameStart = false, gameOver = false;
    MenuScene* menu = new MenuScene(window, opc);
    GameScene* game = NULL;


    while (window->isOpen())
    {
 
        if (!gameStart) {
            switch (opc)
            {
            case 1:
                game = createGame(window, view, false);
                gameStart = true;
                break;
            case 2:
                game = createGame(window, view, true);
                gameStart = true;
                break;
            case 3:
                // por ahora
                opc = 0;
                break;
            case 4:
                exit(1);
                break;
            }

            menu->loop();

        }

        else if (!gameOver) {
            game->loop();
        }
    
    }
    return 0;
}

GameScene* createGame(RenderWindow * window, View * view, bool multiplayer) {
   
    // creamos un un jugador
    Player* dinitrio = new Player("DinitrioSprite.png", Vector2u(3, 2), "arrows", 0.3f, { 206.0f, 206.0f });

    vector<Player> players;
    players.push_back(*dinitrio);

    if (multiplayer) {
        Player* dinoncio = new Player("DinoncioSprite.png", Vector2u(3, 2), "letters", 0.3f, { 180.0f, 206.0f });
        players.push_back(*dinoncio);
    }


    // plataformas para la escena del juego

    // vector de plataformas
    vector<Platform> platforms;
    platforms.push_back(Platform("rock.jpg", Vector2f(100.0f, 200.0f), Vector2f(500.0f, 200.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(400.0f, 200.0f), Vector2f(500.0f, 0.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(1000.0f, 200.0f), Vector2f(0.0f, 600.0f)));

    GameScene* scene = new GameScene(window, view, VIEW_HEIGHT, players, platforms);
    return scene;
}