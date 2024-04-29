//
// Created by elias on 28/11/2022.
//
#include "ConcreteWindow.h"

ConcreteWindow::ConcreteWindow(float w, float h, RenderWindow& wi, StateManager& s)
	: window(wi)
	, stateManager(s) {
	width = w;
	height = h;
	background.loadFromFile("../source/pictures/background.jpg");
	sprite.setTexture(background);
}

bool ConcreteWindow::isOpen() {
	return window.isOpen();
}

void ConcreteWindow::clear() {
	window.clear(Color::Black);
}

void ConcreteWindow::display() {
	window.display();
}

void ConcreteWindow::close() {
	window.close();
}

void ConcreteWindow::checkEvent(char* keyReleases) {
	Event event;
	while(window.pollEvent(event)) {
		if(event.type == Event::Closed) {
			close();
		}

		if(event.type == Event::KeyReleased) {
			if(event.key.code == Keyboard::Key::D) {
				keyReleases[0] = 'D';
			}
			if(event.key.code == Keyboard::Key::A)
				keyReleases[1] = 'A';

			if(event.key.code == Keyboard::Key::Space) {
				keyReleases[2] = 'S';
			}
		}
	}
}

void ConcreteWindow::checkKeyboardInput(char* keyPresses) {
	if(Keyboard::isKeyPressed(Keyboard::A)) {
		keyPresses[0] = 'A';
	}

	if(Keyboard::isKeyPressed(Keyboard::D)) {
		keyPresses[1] = 'D';
	}

	if(Keyboard::isKeyPressed(Keyboard::Space)) {
		keyPresses[2] = 'S';
	}
	if(Keyboard::isKeyPressed(Keyboard::Escape)) {
		/// ik remove de level staat, en dan laat ik de menuState zien
		stateManager.removeState();
		keyPresses[3] = 'E';
	}
}

void ConcreteWindow::drawBackground() {
	window.draw(sprite);
}

float ConcreteWindow::getWindowWidth() {
	return width;
}

float ConcreteWindow::getWindowHeight() {
	return height;
}