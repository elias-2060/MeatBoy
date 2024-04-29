//
// Created by elias on 21/11/2022.
//
#include "Game.h"
shared_ptr<Stopwatch> Stopwatch::stopwatch = nullptr;

Game::Game(float w, float h) {
	width = w;
	height = h;
}
Game::~Game() = default;

void Game::runGame() const {
	//// setting the window
	RenderWindow renderWindow(VideoMode(width, height), "Meat Boy");
	renderWindow.setFramerateLimit(60);
	//// setting the stateManager
	StateManager stateManager;
	ConcreteWindow window(width, height, renderWindow, stateManager);
	//// de stateManager start met een menu state
	stateManager.addState(
		shared_ptr<State>(new MenuState(renderWindow, stateManager, width, height)));

	//// run the program as long as the window is open
	while(window.isOpen()) {
		stateManager.processStateChanges();
		stateManager.getActiveState()->handleInput();
		stateManager.getActiveState()->update();
	}
}
