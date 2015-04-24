#pragma once
#include "GameObject.h"
#include "MissileTypes.h"

class Missile : public GameObject
{
private:
    MissileType missileType;

public:
    // Constructor & Destructor
    Missile(void);
    Missile(int xPos, int yPos, int speed, MissileType type);

    ~Missile(void)
    {
    }

    // Member functions
    void loadSprites();
};