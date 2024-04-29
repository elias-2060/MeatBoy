//
// Created by elias on 22.12.22.
//

#ifndef MEATBOY_MENUSTATE_H
#include "ConcreteWindow.h"
#include "MenuLevelState.h"
#include "State.h"
#include "StateManager.h"
#include "iostream"
#define MEATBOY_MENUSTATE_H
#define MAX_NUMBER_OF_ITEMS 2

/// deze state class is de start menu
class MenuState : public State {
private:
	float width;
	float height;
	int selectedItemIndex;
	RenderWindow& window;
	StateManager& stateManager;
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];
	Texture background;
	Sprite sprite;

public:
	explicit MenuState(RenderWindow& wi, StateManager& s, float w, float h);
	/// initialiseer de menu texts
	void init() override;
	/// handles de input
	void handleInput() override;
	/// updates de menu
	void update() override;
	/// tekent de menu texts
	void draw() override;
	/// schuift de selector 1 omhoog
	void moveUp();
	/// schuift de selector 1 omlaag
	void moveDown();
};
#endif //MEATBOY_MENUSTATE_H
