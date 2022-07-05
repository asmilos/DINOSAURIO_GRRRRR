#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
using namespace std;
using namespace sf;

class Player
{
public:
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Player();

	void Update(float deltaTime);
	void Draw(RenderWindow& window);
	
	
private:
	RectangleShape body;
	Animation animation;

	unsigned int row;
	float speed;
	
	bool faceRight;

};