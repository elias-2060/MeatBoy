//
// Created by elias on 25/11/2022.
//

#ifndef MEATBOY_CONCRETEFACTORY_H
#include "../LogicLibrary/AbstractFactory.h"
#include "GoalView.h"
#include "PlayerView.h"
#include "WallView.h"
#include "memory"
#include "shared_mutex"
#include <SFML/Graphics.hpp>
#define MEATBOY_CONCRETEFACTORY_H
using namespace std;
using namespace sf;

/// dit is de concrete class van de abstractFactory
class ConcreteFactory : public AbstractFactory {
private:
	RenderWindow& window;

public:
	explicit ConcreteFactory(RenderWindow& wi);
	~ConcreteFactory();
	/// creates a player op de gegeven positie
	shared_ptr<PlayerModel> createPlayer(World& w, float x, float y) override;
	/// creates a wall op de gegeven positie met een width en height
	shared_ptr<WallModel> createWall(World& w, float x, float y, float wi, float h) override;
	/// creates a goal op de gegeven positie
	shared_ptr<GoalModel> createGoal(World& w, float x, float y) override;
};
#endif //MEATBOY_CONCRETEFACTORY_H
