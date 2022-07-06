#include "Platform.h"

Platform::Platform(std::string nameTexture, Vector2f size, Vector2f position)
{
	texture = new Texture;
	texture->loadFromFile(nameTexture);

	body.setSize(size);
	body.setOrigin(size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
	 
}
Platform::~Platform()
{

}


void Platform::Draw(RenderWindow& window)
{
	window.draw(body);
}
