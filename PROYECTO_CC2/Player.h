#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	void OnCollision(Vector2f direction);
	
	Vector2f GetPosition() { 
		return body.getPosition();  }
	Collider GetCollider() { 
		return Collider(body);
	}
private:
	RectangleShape body;
	Animation animation;

	unsigned int row;
	float speed;
	
	bool faceRight;
	//Esto es lo de gravedad y salto
	Vector2f velocity;
	bool canJump;
	float jumpHeight;

};