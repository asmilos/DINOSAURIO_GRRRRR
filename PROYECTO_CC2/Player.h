#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collider.h"

using namespace std;
using namespace sf;

class Player
{
public:
	Player(std::string nameTexture, sf::Vector2u imageCount, string controls, float switchTime, Vector2f position);
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
	Texture* texture;
	RectangleShape body;
	Animation* animation;

	unsigned int row;
	float speed;
	
	bool faceRight;

	// controles
	string controls;

	//Esto es lo de gravedad y salto
	Vector2f velocity;
	bool canJump;
	float jumpHeight;

};