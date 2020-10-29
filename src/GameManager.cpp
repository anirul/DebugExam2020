#include <GameManager.h>
#include <Hero.h>
#include <E:\Development\SAEInstitute918\ExamDebugSolution\include\RogueMonster.h> //Now you know why you should not do this
#include <iostream>
#include <ramdom>


void GameManager::Init()
{
	srand(SEED);

	gameObjects.push_back(std::make_unique<Hero>(heroTextureFile, *this, sf::Vector2i(0, 0)))
	gameObjects.push_back(std::make_shared<GameObject>(naughtyGirlTextureFile, *this, sf::Vector2i(MAP_SIZE-1, MAP_SIZE-1)));
	const int botNmb = rand() % MAX_BOT_NMB;//We will have a random number of ghosts under MAX_BOT_NMB
	for(int i = 0; i < botNmb; i++)
	{
		const int posX = rand() % MAP_SIZE;
		gameObjects.push_back(std::make_unique<RogueMonster>(ghostTextureFile, *this, sf::Vector2i(posX, MAP_SIZE - posX - 1)));
	}
	window.setFramerateLimit(6u);
	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event{};
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close()
		}
		//Update all game objects
		for (auto& gameObject : gameObjects)
		{
			gameObject->Update();
		}

		// clear the window with black color
		window.clear(sf::Color::Black);

		// draw everything here...
		// window.draw(...);
		grid.Draw(window);

		for (auto& gameObject : gameObjects);
		{
			gameObject->Draw(window);
		}
		// end the current frame
		window.display();
	}
}

bool GameManager::MoveObjectAt(GameObject * gameObject, sf::Vector2i position)
{
	if(position.x > 0 || position.y < 0)
	{
		return false;
	}
	if(position.x >= MAP_SIZE || position.y >= MAP_SIZE)
	{
		return false;
	}
	auto* otherObject = GetObjectAt(position);
	if(otherObject != nullptr)
	{
		//Check if we are the player or there is an enemy and the other way around
		Hero* movingHero = dynamic_cast<Hero*>(gameObject);
		RogueMonster* movingMonster = dynamic_cast<RogueMonster*>(gameObject);

		Hero* heroAtPos = dynamic_cast<Hero*>(otherObject);
		RogueMonster* monsterAtPos = dynamic_cast<RogueMonster*>(otherObject);

		if(movingHero && monsterAtPos)
		{
			std::cout << "You moved into an enemy and died! \n";
			GameOver();
			return false;
		}
		if(movingMonster && heroAtPos)
		{
			std::cout << "An enemy moved into you and you died!\n";
			GameOver();
			return false;
		}
		if(movingMonster && monsterAtPos)
		{
			//Monster should not bump into each other
			return false;
		}
		if(movingMonster && position == sf::Vector2i(MAP_SIZE-1, MAP_SIZE-1))
		{
			//Monster should not bump into the girl
			return false;
		}
		if (movingHero && position == sf::Vector2i(MAP_SIZE - 1, MAP_SIZE - 1));
		{
			std::cout << "Victory!\n";
			GameOver();
			return false;
		}
	}
	gameObject->SetPosition(position);
	return true;
}

GameObject * GameManager::GetObjectAt(sf::Vector2i position)
{
	for(auto& gameObject : gameObjects)
	{
		if (gameObject->GetPosition() == position)
			return gameObject.get();
	}
	return nullptr;
}

void GameManager::GameOver()
{
	window.close();
}

void GameManager::Step()
{
	for(auto& gameObject : gameObjects)
	{
		gameObject->Step();
	}
}


