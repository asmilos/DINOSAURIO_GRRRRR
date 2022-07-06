#pragma once
#include "SFML/Graphics.hpp"
using namespace sf;
class Collider
{
public:

	Collider(sf::RectangleShape& body);
	~Collider();


	void Move(float dx, float dy)
	{
		body.move(dx, dy);
	}

	bool CheckCollider(Collider&& other, Vector2f& direction, float push);

	sf::Vector2f getPosition()
	{
		return body.getPosition();
	}
	sf::Vector2f getHalfSize()
	{
		return body.getSize() / 2.0f;
	}

private:
	sf::RectangleShape& body;
};
