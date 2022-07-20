#pragma once
#include"SFML/Graphics.hpp"
#include"Platform.h"
#include"Player.h"
#include"Scene.h"
#include<vector>
using namespace sf;

class GameScene : public Scene
{
public:
	GameScene(RenderWindow* window,View * view, const float VIEW_HEIGHT, vector<Player> players,vector<Platform> platforms);
	void loop();
	void ResizeView();
	void events();
private:
	View* view;
	vector<Player> players;
	vector<Platform> platforms;

	float deltaTime;
	Clock clock;
	const float VIEW_HEIGHT;

	Clock* clockTimer;
	Time* timeTimer;
	int totalTime;
	Text* textTimer;
};

