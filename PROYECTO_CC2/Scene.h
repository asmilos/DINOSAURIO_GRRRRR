#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Scene
{
public:
	Scene();
	Scene(RenderWindow * window);
	~Scene();

	virtual void loop();
	virtual void events();

protected:
	RenderWindow* window;
	Event* event;
	Texture* imgBackground;
	Sprite* background;
};

