#include "MissileManager.h"
#include "PhysicsManager.h"
#include "Missile.h"
using namespace std;

MissileManager::MissileManager(void)
{
}

MissileManager::~MissileManager(void)
{
}

void MissileManager::shootMissile(int xPos, int yPos, int speed, MissileType type)
{
	if(SDL_GetTicks() < timer)
		return;

	missileInProgress.push_back(new Missile(xPos, yPos, speed, type));

	timer = SDL_GetTicks() + 500;
}

void MissileManager::updateMissileInProgress()
{
	for (unsigned int i = 0 ; i < missileInProgress.size(); i++)
	{
		missileInProgress.at(i)->getCurrentSprite()->evolueFromVector();
		missileInProgress.at(i)->updateAnimation();
	}
}

void MissileManager::manageVectorSize(PhysicsManager* physicsManager)
{
	// Regarde les missiles en dehors de l'écran, et les détruit
	bool erased = false;
	for (std::vector<Missile*>::iterator it = missileInProgress.begin() ; it != missileInProgress.end() ; )
	{
		erased = false;
		if(physicsManager->isOutOfScreen((*it)->getXPos(), (*it)->getYPos()))
		{
			erased = true;
			it = missileInProgress.erase(it);
		}

		if(!erased)
			++it;
		else if(it == missileInProgress.end())
			break;
	}
}