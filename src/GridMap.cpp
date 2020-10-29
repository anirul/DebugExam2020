#include <iostream>
#include <GridMap.h>

GridMap::GridMap()
{
	if (!groundTileTexture.loadFromFile(groundTextureFile))
	{
		std::cerr << "[Error] Could not load texture: " << groundTextureFile << "\n";
	}

	gridSize = sf::Vector2f(GRID_CELL_SIZE, GRID_CELL_SIZE);
	gridScale = sf::Vector2f(
		gridSize.x / groundTileTexture.getSize().x,
		gridSize.y / groundTileTexture.getSize().y);
	for (int y = 0; y < MAP_SIZE; y++)
	{
		for (int x = 0; x < MAP_SIZE; x++)
		{
			grid[x][y].setTexture(groundTileTexture);
			grid[x][y].setScale(gridScale);
			grid[x][y].setOrigin(gridSize / 2.0f);
			grid[x][y].setPosition(sf::Vector2f(x*gridSize.x, y*gridSize.y) + 2.0f*gridSize);
		}
	}
}

void GridMap::Draw(sf::RenderWindow & window)
{
	for (auto& line : grid)
	{
		for (auto& tile : line)
		{
			window.draw(tile);
		}
	}
}

sf::Vector2f GridMap::GetGridSize()
{
	return gridSize;
}

sf::Vector2f GridMap::GetGridScale()
{
	return gridScale/2.0f;
}
