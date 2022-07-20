#pragma once
#include<SFML/Graphics.hpp>
#include"Scene.h"

using namespace sf;

class MenuScene : public Scene
{
public:
	MenuScene();
	MenuScene(RenderWindow * window, int & opc);
	~MenuScene();
	void loop();
	void events();
private:
	int* opc;
	int tempOpc;

	RectangleShape background;
	Texture * texture;

	Vector2f ptrPosition;

	Texture* txt_pointer;
	Sprite* spt_pointer;
};

