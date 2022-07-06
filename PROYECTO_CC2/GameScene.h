#pragma once
#include"SFML/Graphics.hpp"
#include"Platform.h"
#include"Player.h"
#include<vector>
using namespace sf;

class GameScene
{
public:
	GameScene(RenderWindow* window,View * view, const float VIEW_HEIGHT, Player *& player,vector<Platform> platforms);
	void gameloop();
	void ResizeView();
	void events();
private:
	RenderWindow* window;
	View* view;
	Player* player;
	vector<Platform> platforms;

	Event* event;

	float deltaTime;
	Clock clock;
	const float VIEW_HEIGHT;
};

