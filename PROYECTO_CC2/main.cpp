#include <SFML/Graphics.hpp>
#include "iostream"
#include "Player.h"
#include "Platform.h"
#include "GameScene.h"
#include "vector"

using namespace sf;
using namespace std;

static const float VIEW_HEIGHT = 400.0f;//tamaño de la vista

int main()
{
    // creamos nuestra pantalla
    RenderWindow * window = new RenderWindow(VideoMode(800, 600), "SFML", Style::Close | Style::Resize);
    // primer vector es el centro, y el resto su tamaño de la vista
    View * view = new View(Vector2f(0.0f, 0.0f), Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));

    // Creando los jugadores
    Player* dinitrio = new Player("DinitrioSprite.png", Vector2u(3, 2), "arrows", 0.3f, 150.0f, 50.0f);
    Player* dinoncio = new Player("DinitrioSprite.png", Vector2u(3, 2), "letters", 0.3f, 150.0f, 50.0f);

    vector<Player> players;
    players.push_back(*dinitrio);
    players.push_back(*dinoncio);

    //NIVEL1
    // vector de plataformas
    vector<Platform> platforms;
    //rock left
    platforms.push_back(Platform("rock.jpg", Vector2f(20.0f, 1200.0f), Vector2f(0.0f, 600.0f)));
    //rock right
    platforms.push_back(Platform("rock.jpg", Vector2f(20.0f, 1200.0f), Vector2f(600.0f, 600.0f)));
    //roca suelo
    platforms.push_back(Platform("rock.jpg", Vector2f(400.0f, 200.0f), Vector2f(200.0f, 600.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(100.0f, 200.0f), Vector2f(550.0f, 600.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(50.0f, 50.0f), Vector2f(570.0f, 480.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(30.0f, 70.0f), Vector2f(580.0f, 450.0f)));
    //superficie01
    platforms.push_back(Platform("rock.jpg", Vector2f(50.0f, 20.0f), Vector2f(35.0f, 380.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(10.0f, 20.0f), Vector2f(150.0f, 380.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(50.0f, 20.0f), Vector2f(300.0f, 380.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(50.0f, 20.0f), Vector2f(470.0f, 380.0f)));
    //superficie02
    platforms.push_back(Platform("rock.jpg", Vector2f(400.0f, 20.0f), Vector2f(400.0f, 250.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(150.0f, 260.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(100.0f, 390.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(100.0f, 310.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(30.0f, 30.0f), Vector2f(20.0f, 355.0f)));
    //superficiefinal
    platforms.push_back(Platform("rock.jpg", Vector2f(30.0f, 5.0f), Vector2f(575.0f, 210.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(500.0f, 165.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(400.0f, 145.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(300.0f, 125.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(15.0f, 5.0f), Vector2f(200.0f, 105.0f)));
    platforms.push_back(Platform("rock.jpg", Vector2f(60.0f, 5.0f), Vector2f(20.0f, 120.0f)));
    platforms.push_back(Platform("puerta.png", Vector2f(30.0f, 60.0f), Vector2f(5.0f, 89.0f)));

    

    GameScene* scene = new GameScene(window,view,VIEW_HEIGHT,players,platforms);


    while (window->isOpen())
    {
        scene->loop();
    }

    return 0;
}
