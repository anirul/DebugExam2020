#include <iostream>
#include <GameObject.h>
#include <GlobalGameJam.h>
#include <GameManager.h>


GameObject::GameObject(std::string textureFileName, GameManager& gameManagerRef, sf::Vector2i originPos) :
	position(originPos), gameManager(gameManagerRef)
{
	if (texture.loadFromFile(textureFileName))
	{
		sprite.setTexture(texture);
		sprite.setOrigin(sf::Vector2f(
			texture.getSize().x,
			texture.getSize().y));

		sprite.setScale(gameManager.grid.GetGridScale());
	}
	else
	{
		std::cerr << "[Error] Could not load: " << textureFileName << "/n";
	}
}

void GameObject::Update()
{
	sprite.setPosition(sf::Vector2f(position.x*GRID_CELL_SIZE, position.y*GRID_CELL_SIZE)+2.0f*gameManager.grid.GetGridSize());
}

void GameObject::Draw(sf::RenderWindow & window)
{
	window.draw(sprite);
}

sf::Vector2i GameObject::GetPosition()
{
	return position
}

void GameObject::SetPosition(sf::Vector2i newPos)
{
	position = newPos;
}
