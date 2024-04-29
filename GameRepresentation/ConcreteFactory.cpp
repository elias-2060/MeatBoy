//
// Created by elias on 25/11/2022.
//
#include "ConcreteFactory.h"

ConcreteFactory::ConcreteFactory(RenderWindow& wi)
	: window(wi) { }

ConcreteFactory::~ConcreteFactory() = default;

shared_ptr<PlayerModel> ConcreteFactory::createPlayer(World& w, float x, float y) {
	shared_ptr<PlayerModel> playerModel = make_shared<PlayerModel>(w, x, y);
	auto view = make_shared<PlayerView>(*playerModel, window, "../source/pictures/player.jpg");
	playerModel->addObserver(view);
	return playerModel;
}

shared_ptr<WallModel> ConcreteFactory::createWall(World& w, float x, float y, float wi, float h) {
	shared_ptr<WallModel> wallModel = make_shared<WallModel>(w, x, y, wi, h);
	auto view = make_shared<WallView>(*wallModel, window, "../source/pictures/wall.jpg");
	wallModel->addObserver(view);
	return wallModel;
}

shared_ptr<GoalModel> ConcreteFactory::createGoal(World& w, float x, float y) {
	shared_ptr<GoalModel> goalModel = make_shared<GoalModel>(w, x, y);
	auto view = make_shared<GoalView>(*goalModel, window, "../source/pictures/goal.png");
	goalModel->addObserver(view);
	return goalModel;
}