#ifndef DBG_EXAM_GRID_H
#define DBG_EXAM_GRID_H
#include <array>

#include <Globals.h>
#include <SFML/Graphics.hpp>

class GridMap
{
public:
	GridMap();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetGridSize();
	sf::Vector2f GetGridScale();
private:
	std::array<std::array<sf::Sprite, MAP_SIZE>, MAP_SIZE> grid;
	sf::Texture groundTileTexture;
	sf::Vector2f gridSize;
	sf::Vector2f gridScale;
};


#endif