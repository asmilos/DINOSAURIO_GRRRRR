#include "Player.h"
using namespace sf;

Player::Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight):

animation(texture, imageCount, switchTime)
{
		this->speed = speed;
		this->jumpHeight = jumpHeight;
		row = 0;
		faceRight = true;
		body.setSize(Vector2f(100.0f, 100.0f));
		body.setOrigin(body.getSize() / 2.0f);
		body.setPosition(206.0f, 206.0f);
		body.setTexture(texture);

}

Player::~Player()
{

}
void Player::Update(float deltaTime)
{   //Velocity tiene que ver con la gravedad
	velocity.x = 0.0f;

	

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		velocity.x -= speed ;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		velocity.x += speed ;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && canJump)
	{
		canJump = false;

		velocity.y = -sqrtf(2.0f * 981.0f * jumpHeight);
	}

	velocity.y += 981.0f * deltaTime;

	if (velocity.x == 0.0f)
	{
		row = 0;

	}
	else
	{
		row = 1;

		if (velocity.x > 0.0f)
			faceRight = true;
		else
			faceRight = false;
	}
	animation.Update(row, deltaTime, faceRight);
	body.setTextureRect(animation.uvRect);
	body.move(velocity * deltaTime);
}

void Player::Draw(RenderWindow& window) 
{
	window.draw(body);

}

void Player::OnCollision(Vector2f direction)
{
	if (direction.x < 0.0f)
	{   
		//Colision on the left
		velocity.x = 0.0f;

	}
	else if (direction.x > 0.0f)
	{
		//Colision on the right 
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Colision on the bottom(creo que es abajo)
		velocity.y = 0.0f;
		canJump = true;
	}
	else if (direction.y > 0.0f)
	{
		//Colision con arriba
		velocity.y = 0.0f;
	}
}
