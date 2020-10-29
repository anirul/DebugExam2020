#include <Hero.h>
#include <GameManager.h>

void Hero::Update()
{
	GameObject::Update();

	sf::Vector2i moveDirection;
	//Get Input status
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !previousLeftKey)
	{
		moveDirection.x = -1;
	}
	previousLeftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !previousRightKey)
	{
		moveDirection.x = -1;
	}
	previousRightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !previousUpKey)
	{
		moveDirection.y = -1;
	}
	previousUpKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !previousDownKey)
	{
		moveDirection.y = -1;
	}
	previousDownKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);

	if(moveDirection == sf::Vector2i())
	{
		if(gameManager.MoveObjectAt(this, position + moveDirection))
		{
			gameManager.Step();
		}
	}
}

void Hero::Step()
{
}

