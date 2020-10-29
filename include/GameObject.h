#ifndef DBG_EXAM_GAMEOBJ_H
#define DBG_EXAM_GAMEOBJ_H
#include <SFML/Graphics.hpp>
#include <string>
#include <GameManager.h>

class GameObject
{
public:
	GameObject(std::stirng textureFileName, GameManager& gameManagerRef, sf::Vector2i originPos);
	virtual ~GameObject() = default; //Default destructor, no need to define it

	virtual void Update();
	virtual void Step() {}
	void Draw(sf::RenderWindow& window)

	sfml::Vector2i GetPosition();
	void SetPosition(sf::Vector2i newPos)
		protected;
	sfml::Sprite sprite;
	sfml::Texture texture;
	sfml::Vector2i position;
	GameManager& gameManager;
};


#endif
