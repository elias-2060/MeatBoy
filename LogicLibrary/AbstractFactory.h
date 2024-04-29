//
// Created by elias on 25/11/2022.
//

#ifndef MEATBOY_ABSTRACTFACTORY_H
#include "World.h"
#define MEATBOY_ABSTRACTFACTORY_H

/// pure virtual class voor de factory waar ik mijn entities in de concrete
/// class maak
class AbstractFactory {
public:
	virtual shared_ptr<PlayerModel> createPlayer(World& w, float x, float y) = 0;
	virtual shared_ptr<WallModel> createWall(World& w, float x, float y, float wi, float h) = 0;
	virtual shared_ptr<GoalModel> createGoal(World& w, float x, float y) = 0;
};

#endif // MEATBOY_ABSTRACTFACTORY_H
