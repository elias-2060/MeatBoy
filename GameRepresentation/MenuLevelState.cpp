//
// Created by elias on 26.12.22.
//
#include "MenuLevelState.h"

MenuLevelState::MenuLevelState(RenderWindow& wi, StateManager& s, float w, float h)
	: window(wi)
	, stateManager(s) {
	width = w;
	height = h;
	play = false;
	selectedItemIndex = 1;
	max = countFiles();
}

float MenuLevelState::countFiles() {
	float count = 0;
	for(int i = 0; i < MAX_ITEMS; ++i) {
		string file = "../source/levels/level";
		file += to_string(i);
		file += ".xml";
		ifstream f(file);
		if(f.good())
			count++;
	}
	return count;
}

void MenuLevelState::init() {
	if(!font.loadFromFile("../source/fonts/ARIAL.TTF") or
	   !background.loadFromFile("../source/pictures/menu.jpg")) {
		cout << "ERROR: failed to load file!" << endl;
	}
	sprite.setTexture(background);
	sprite.setTextureRect(IntRect(0, 30, width, height));

	for(int i = 1; i <= max + 1; ++i) {
		menu[i].setFont(font);
		if(i == 1)
			menu[i].setColor(Color::Red);
		else
			menu[i].setColor(Color::Black);
		string name;
		if(i != max + 1) {
			name = "Level ";
			name += to_string(i);
		} else if(i == max + 1) {
			name = "Return";
		}
		menu[i].setString(name);
		menu[i].setPosition(width / 2 - 60, height / (MAX_ITEMS)*i + 200);
	}
}
void MenuLevelState::draw() {
	window.clear();
	window.draw(sprite);
	if(!play) {
		for(int i = 0; i < MAX_ITEMS; ++i) {
			window.draw(menu[i]);
		}
	}
	window.display();
}

void MenuLevelState::moveUp() {
	if(selectedItemIndex - 1 >= 1) {
		menu[selectedItemIndex].setColor(Color::Black);
		selectedItemIndex--;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void MenuLevelState::moveDown() {
	if(selectedItemIndex + 1 <= max + 1) {
		menu[selectedItemIndex].setColor(Color::Black);
		selectedItemIndex++;
		menu[selectedItemIndex].setColor(Color::Red);
	}
}

void MenuLevelState::update() {
	draw();
}

void MenuLevelState::handleInput() {
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
				for(int i = 1; i <= max; ++i) {
					if(selectedItemIndex == i) {
						string path = "../source/levels/level";
						string path2 = "../source/levels/level";
						string path3 = "../source/levels/level";
						path += to_string(i);
						path += ".xml";
						path2 += to_string(i + 1);
						path2 += ".xml";
						path3 += to_string(i + 2);
						path3 += ".xml";
						if(i + 1 > max)
							path2 = "geen";
						if(i + 2 > max)
							path3 = "geen";
						stateManager.addState(make_shared<LevelState>(
							window, stateManager, width, height, path, path2, path3));
					}
				}
				if(selectedItemIndex == max + 1 && !play) {
					stateManager.removeState();
				}
			}
		}
	}
}