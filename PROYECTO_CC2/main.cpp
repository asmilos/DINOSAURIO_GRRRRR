#include <SFML/Graphics.hpp>
#include "iostream"
#include "Player.h"
#include "Platform.h"
#include "GameScene.h"
#include "MenuScene.h"
#include "vector"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 400.0f;//tamaño de la vista

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
    Player* dinitrio = new Player("Images/DinitrioSprite.png", Vector2u(3, 2), "arrows", 0.3f, { 206.0f, 206.0f });
    // Creando los jugadores

    vector<Player> players;
    players.push_back(*dinitrio);

    if (multiplayer) {
        Player* dinoncio = new Player("Images/DinoncioSprite.png", Vector2u(3, 2), "letters", 0.3f, { 180.0f, 206.0f });
        players.push_back(*dinoncio);
    }


    // plataformas para la escena del juego

    //NIVEL1
    // vector de plataformas
    vector<Platform> platforms;
    //rock left
    platforms.push_back(Platform("Images/Images/rock.jpg", Vector2f(20.0f, 1200.0f), Vector2f(0.0f, 600.0f)));
    //rock right
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(20.0f, 1200.0f), Vector2f(600.0f, 600.0f)));
    //roca suelo
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(400.0f, 200.0f), Vector2f(200.0f, 600.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(100.0f, 200.0f), Vector2f(550.0f, 600.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(50.0f, 50.0f), Vector2f(570.0f, 480.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(30.0f, 70.0f), Vector2f(580.0f, 450.0f)));
    //superficie01
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(50.0f, 20.0f), Vector2f(35.0f, 380.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(10.0f, 20.0f), Vector2f(150.0f, 380.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(50.0f, 20.0f), Vector2f(300.0f, 380.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(50.0f, 20.0f), Vector2f(470.0f, 380.0f)));
    //superficie02
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(400.0f, 20.0f), Vector2f(400.0f, 250.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(150.0f, 260.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(100.0f, 390.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(100.0f, 310.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(30.0f, 30.0f), Vector2f(20.0f, 355.0f)));
    //superficiefinal
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(575.0f, 210.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(500.0f, 165.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(400.0f, 145.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(300.0f, 125.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(200.0f, 105.0f)));
    platforms.push_back(Platform("Images/rock.jpg", Vector2f(60.0f, 5.0f), Vector2f(20.0f, 120.0f)));
    platforms.push_back(Platform("Images/puerta.png", Vector2f(30.0f, 60.0f), Vector2f(5.0f, 89.0f)));

    GameScene* scene = new GameScene(window, view, VIEW_HEIGHT, players, platforms);
    return scene;
}   

