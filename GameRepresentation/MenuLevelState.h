//
// Created by elias on 26.12.22.
//

#ifndef MEATBOY_MENULEVELSTATE_H
#include "ConcreteWindow.h"
#include "LevelState.h"
#include "State.h"
#include "StateManager.h"
#include "fstream"
#include "iostream"
#define MEATBOY_MENULEVELSTATE_H
#define MAX_ITEMS 10

/// laat de curr levels zien op het screen
class MenuLevelState : public State {
private:
	float width;
	float height;
	int selectedItemIndex;
	bool play;
	float max;
	RenderWindow& window;
	StateManager& stateManager;
	Font font;
	Text menu[MAX_ITEMS];
	Texture background;
	Sprite sprite;

public:
	explicit MenuLevelState(RenderWindow& wi, StateManager& s, float w, float h);
	/// kijkt hoeveel levels er zijn
	float countFiles();
	/// initialiseerd de texts van de menuLevel
	void init() override;
	/// handles de input
	void handleInput() override;
	/// updates de menuLevel
	void update() override;
	/// tekent de texts van de menuLevel
	void draw() override;
	/// schuift de current level selector 1 omhoog
	void moveUp();
	/// schuift de current level selector 1 omlaag
	void moveDown();
};
#endif //MEATBOY_MENULEVELSTATE_H
