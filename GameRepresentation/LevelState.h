//
// Created by elias on 22.12.22.
//

#ifndef MEATBOY_LEVELSTATE_H
#include "../LogicLibrary/World.h"
#include "ConcreteFactory.h"
#include "ConcreteWindow.h"
#include "State.h"
#include "StateManager.h"
#define MEATBOY_LEVELSTATE_H

/// state waar de gameplay word gespeeld
class LevelState : public State {
private:
	RenderWindow& renderWindow;
	float width;
	float height;
	string path;
	string pathNext;
	string pathNext2;
	StateManager& stateManager;

public:
	LevelState(
		RenderWindow& wi, StateManager& s, float w, float h, string p, string pNext, string pNext2);
	/// initialiseer de level
	void init() override;
	/// handles de input
	void handleInput() override;
	/// tekent de level
	void draw() override;
	/// maakt een world aan en runt de game loop
	void update() override;
};

#endif //MEATBOY_LEVELSTATE_H
