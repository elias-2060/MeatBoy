//
// Created by elias on 20.12.22.
//
#ifndef MEATBOY_STATE_H
#define MEATBOY_STATE_H

/// pure virtual class voor de states
class State {
public:
	virtual void init() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void handleInput() = 0;
};
#endif //MEATBOY_STATE_H
