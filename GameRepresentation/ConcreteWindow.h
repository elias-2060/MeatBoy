//
// Created by elias on 28/11/2022.
//

#ifndef MEATBOY_WINDOW_H
#include "../LogicLibrary/AbstractWindow.h"
#include "StateManager.h"
#include <SFML/Graphics.hpp>
#define MEATBOY_WINDOW_H
using namespace sf;

/// dit is de concrete class van de abstractWindow
class ConcreteWindow : public AbstractWindow {
private:
	RenderWindow& window;
	StateManager& stateManager;
	Texture background;
	Sprite sprite;
	float width;
	float height;

public:
	/// maakt een window view
	ConcreteWindow(float w, float h, RenderWindow& wi, StateManager& s);
	/// kijkt of de window nog altijd open is
	bool isOpen() override;
	/// displayed alles wat je gedrawed hebt op de screen
	void display() override;
	/// cleared de screen
	void clear() override;
	/// kijkt of er een release event is gebeurd
	void checkEvent(char* keyReleases) override;
	/// closed de screen
	void close() override;
	/// kijkt of er een keypress is gebeurd
	void checkKeyboardInput(char* keyPresses) override;
	/// tekent de background
	void drawBackground() override;
	/// returned de width van de window
	float getWindowWidth() override;
	/// returned de height van de window
	float getWindowHeight() override;
};

#endif //MEATBOY_WINDOW_H
