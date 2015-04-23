#pragma once
#include "GameObject.h"
#include "EnemyTypes.h"

class Enemy : public GameObject
{
	private:
		int ennemySpeed;
		EnemyType type;

	public:
		// Constructor & Destructor
		Enemy(void);
		Enemy(int speed, EnemyType type);
		~Enemy(void) { }

        // Member functions
        void loadSprites();
};