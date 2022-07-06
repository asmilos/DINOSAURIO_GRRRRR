#pragma once
#include "SFML/Graphics.hpp"
#include "Collider.h"

using namespace sf;

class Platform
{
public:
	Platform(Texture* texture, Vector2f size, Vector2f position);
	~Platform(); 

	void Draw(RenderWindow& window);
	Collider GetCollider() { return Collider(body);
	}

private:
	RectangleShape body;
};

