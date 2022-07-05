#include "Player.h"
using namespace sf;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed):

animation(texture, imageCount, switchTime)
{
		this->speed = speed;
		row = 0;
		faceRight = true;
		body.setSize(Vector2f(100.0f, 100.0f));
		body.setPosition(206.0f, 206.0f);
		body.setTexture(texture);

}

Player::~Player()
{

}
void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		movement.x -= speed * deltaTime;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		movement.x += speed * deltaTime;

	if (movement.x == 0.0f)
	{
		row = 0;

	}
	else
	{
		row = 1;

		if (movement.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(movement);
}

void Player::Draw(RenderWindow& window) 
{
	window.draw(body);

}
