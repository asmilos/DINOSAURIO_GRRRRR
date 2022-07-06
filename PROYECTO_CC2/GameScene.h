#pragma once
#include"SFML/Graphics.hpp"
#include"Platform.h"
#include"Player.h"
#include<vector>
using namespace sf;

class GameScene
{
public:
	GameScene(RenderWindow* window,View * view, const float VIEW_HEIGHT, vector<Player> players,vector<Platform> platforms);
	void loop();
	void ResizeView();
	void events();
private:
	RenderWindow* window;
	View* view;
	vector<Player> players;
	vector<Platform> platforms;

	Event* event;

	float deltaTime;
	Clock clock;
	const float VIEW_HEIGHT;

	Texture* imgBackground;
	Sprite* background;
};

