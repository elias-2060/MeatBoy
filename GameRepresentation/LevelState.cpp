//
// Created by elias on 22.12.22.
//
#include "LevelState.h"

LevelState::LevelState(
	RenderWindow& wi, StateManager& s, float w, float h, string p, string pNext, string pNext2)
	: renderWindow(wi)
	, stateManager(s) {
	path = std::move(p);
	pathNext = std::move(pNext);
	pathNext2 = std::move(pNext2);
	width = w;
	height = h;
}

void LevelState::init() { }

void LevelState::draw() { }

void LevelState::handleInput() { }

void LevelState::update() {
	ConcreteFactory factory(renderWindow);
	ConcreteWindow window(width, height, renderWindow, stateManager);
	World world(window, factory);
	const char* c = path.data();
	world.init(c);
	world.runGameLoop();
	/// als de player de goal heeft geraakt, dan gaat de player naar de next level
	if(world.getNextLevel() && pathNext != "geen") {
		stateManager.addState(make_shared<LevelState>(
			renderWindow, stateManager, width, height, pathNext, pathNext2, "geen"));
	}
}