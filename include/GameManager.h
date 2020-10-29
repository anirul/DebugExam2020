#ifndef DBG_EXAM_GAMEMANAGER_H
#define DBG_EXAM_GAMEMANAGER_H

#include <memory>
#include <BadGridMap.h>
#include <GameObject.h>

class GameManager
{
	public;

	GridMap grid;

	GameManager() = default;
	void Start();
	bool MoveGameAt(GameObject* gameObject, sf::Vector2i position);
	GameObject* GetObjectAt(sf::Vector2i position);
	void GameOver();
	void Step()
private:
	std::list<std::unique_ptr<GameObject>> gameObjects;
	sf::RenderWindow* window{ sf::VideoMode(SCREEN_SIZE.x, SCREEN_SIZE.y), "Debug Exam 3" };
};



#endif
