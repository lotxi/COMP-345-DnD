#include "Monster.h"
#include "Pathfinder.h"
#include <ctime>

Monster::Monster():LivingEntity('M')
{
	
}

void Monster::simulate(Map* map, Pathfinder* pathfinder)
{
	if (pathfinder == nullptr) {
		int side = rand() % 4;
		switch(side)
		{
		case 1:
			map->moveEntity(this, getPositionX() + 1, getPositionY());
			break;
		case 2:
			map->moveEntity(this, getPositionX() - 1, getPositionY());
			break;
		case 3:
			map->moveEntity(this, getPositionX(), getPositionY()+1);
			break;
		case 4:
			map->moveEntity(this, getPositionX(), getPositionY()-1);
			break;
		}

		return;
	}
	std::vector<Node*> path = pathfinder->getPath(getPositionX(), getPositionY());
	if (path.size() > 0 && path.size() < 8)
	{
		Node* nextNode = path[path.size()-1];
		map->moveEntity(this, nextNode->x, nextNode->y);
	}
}

bool Monster::interact(Map* map, Entity* entity)
{
	if(Character* c = dynamic_cast<Character*>(entity))
	{
		if(hit(c->getStrength()*2))
		{
			map->removeEntity(getPositionX(), getPositionY());
		}
		return true;
	}
	return false;
}
