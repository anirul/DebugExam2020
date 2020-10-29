#ifndef DBG_EXAM_HERO_H
#define DBG_EXAM_HERO_H

class GameObject;
class Hero : public GameObject
{
	using GameObject::GameObject;
	void Update() override;
	void Step() override;
private:
	bool previousLeftKey = false;
	bool previousRightKey = false;
	bool previousUpKey = false;
	bool previousDownKey = false;
};

#endif