#ifndef DBG_EXAM_MONSTER_H
#define DBG_EXAM_MONSTER_H

#include <GameObject.h>

class RogueMnoster : public GameObject
{
	using GameObject::GameObject;
	void Update() override;
	void Step() override;
};

#endif