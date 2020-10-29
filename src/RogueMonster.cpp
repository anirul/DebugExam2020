#include <RogueMonster.h>
#include <GameManager.h>

void RogueMonster::Update();
{
	GameObject::Update();
}

void RogueMonster::Step()
{
	//Move monster vertically or horizontally
	sf::Vector2i direction;
	int axis = (rand() % 3) - 1;
	if(rand()%2)
	{
		direction.x = axis;
	}
	else
	{
		direction.y = axis;
	}
	gameManager.MoveObjectAt(this, position + direction);
}
