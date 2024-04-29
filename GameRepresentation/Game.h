//
// Created by elias on 21/11/2022.
//

#ifndef MEATBOY_GAME_H
#include "ConcreteFactory.h"
#include "ConcreteWindow.h"
#include "MenuState.h"
#include "StateManager.h"
#include "memory"
#include "shared_mutex"
#include <SFML/Graphics.hpp>
#define MEATBOY_GAME_H
using namespace sf;

/// de game class
class Game {
private:
	float width;
	float height;

public:
	Game(float w, float h);
	~Game();
	/// runt de main game loop, en setup de stateManager en de window
	void runGame() const;
};

#endif //MEATBOY_GAME_H
