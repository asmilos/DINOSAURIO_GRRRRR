#include "Collider.h"
using namespace std;
using namespace sf;

Collider::Collider(RectangleShape& body):
	body(body)
{

}

Collider::~Collider()
{

}

// pasa el objeto en si temporalmente
bool Collider::CheckCollider(Collider&& other, Vector2f& direction, float push)
{ 
	Vector2f otherPosition = other.getPosition();
	Vector2f otherHalfSize = other.getHalfSize();
	Vector2f thisPosition = getPosition();
	Vector2f thisHalfSize = getHalfSize();

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);


	if (intersectX < 0.0f && intersectY < 0.0f)
	{
		push = min(max(push, 0.0f), 1.0f);

		if (abs(intersectX) < abs(intersectY))
		{
			if (deltaX > 0.0f)
			{
				Move(intersectX * (1.0f - push), 0.0f);
				other.Move(-intersectX * push, 0.0f);
				//Esta parte es lo de gravedad y salto
				    direction.x = 1.0f;
					direction.y = 0.0f;
			}
			else
			{
				Move(-intersectX * (1.0f - push), 0.0f);
				other.Move(intersectX * push, 0.0f);
				//Esta parte es lo de gravedad y salto
				direction.x = -1.0f;
				direction.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, intersectY * (1.0f - push));
				other.Move(0.0f, -intersectY * push);
				//Esta parte es lo de gravedad y salto
				direction.x = 0.0f;
				direction.y = 1.0f;
			}
			else
			{
				Move(0.0f, -intersectY * (1.0f - push));
				other.Move(0.0f, intersectY * push);
				//Esta parte es lo de gravedad y salto
				direction.x = 0.0f;
				direction.y = -1.0f;
			}
		}

		return true;
	}
	return false;
}
