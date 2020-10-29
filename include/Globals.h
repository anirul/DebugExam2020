#ifdef DBG_EXAM_GLOBALS_H
#define DBG_EXAM_GLOBALS_H
#include <SFML/System/Vector2.hpp>

const int MAP_SIZE = 15;
const int GRID_CELL_SIZE = 32;
const auto SCREEN_SIZE = sf::Vector2i(544,544);
const int SEED = 404;
const int MAX_BOT_NMB = 10;
//Texture path
const std::string groundTextureFile = "data/obviously_bad_ground.png";
const std::string heroTextureFile = "data/hero.png";
const std::string girlTextureFile = "data/bad_girl.png";
const std::string ghostTextureFile = "data/ghost.png";


#endif