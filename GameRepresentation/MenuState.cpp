//
// Created by elias on 22.12.22.
//
#include "MenuState.h"

MenuState::MenuState(RenderWindow& wi, StateManager& s, float w, float h)
	: window(wi)
	, stateManager(s) {
	width = w;
	height = h;
	selectedItemIndex = 0;
}

void MenuState::init() {
	if(!font.loadFromFile("../source/fonts/ARIAL.TTF") or
	   !background.loadFromFile("../source/pictures/menu.jpg")) {
		cout << "ERROR: failed to load file!" << endl;
	}
	sprite.setTexture(background);
	sprite.setTextureRect(IntRect(0, 30, width, height));

	menu[0].setFont(font);
	menu[0].setColor(Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(width / 2 - 40, height / (MAX_NUMBER_OF_ITEMS + 1) * 1);

	menu[1].setFont(font);
	menu[1].setColor(Color::Black);
	menu[1].setString("Exit");
	menu[1].setPosition(width / 2 - 40, height / (MAX_NUMBER_OF_ITEMS + 1) * 2);
}
void MenuState::draw() {
	window.clear();
	window.draw(sprite);
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		window.draw(menu[i]);
	}
	window.display();
}

void MenuState::moveUp() {
	if(selectedItemIndex - 1 >= 0) {
		menu[selectedItemIndex].setColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void MenuState::moveDown() {
	if(selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS) {
		menu[selectedItemIndex].setColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void MenuState::update() {
	draw();
}

void MenuState::handleInput() {
	Event event;
	while(window.pollEvent(event)) {
		if(event.type == Event::Closed) {
			window.close();
		}
		if(event.type == Event::KeyPressed) {
			if(event.key.code == Keyboard::Key::Up)
				moveUp();
			if(event.key.code == Keyboard::Key::Down)
				moveDown();
			if(event.key.code == Keyboard::Key::Return) {
				if(selectedItemIndex == 0) {
					stateManager.addState(
						make_shared<MenuLevelState>(window, stateManager, width, height), false);
				} else if(selectedItemIndex == 1) {
					window.close();
				}
			}
		}
	}
}