//
// Created by elias on 22.12.22.
//
#include "StateManager.h"

StateManager::StateManager() {
	isRemoving = false;
	isAdding = false;
	isReplacing = false;
}

StateManager::~StateManager() = default;

void StateManager::addState(shared_ptr<State> newS, bool isR) {
	isAdding = true;
	isReplacing = isR;
	newState = std::move(newS);
}

void StateManager::removeState() {
	isRemoving = true;
}

void StateManager::processStateChanges() {
	if(isRemoving && !states.empty()) {
		states.pop();
		isRemoving = false;
	}
	if(isAdding) {
		if(!states.empty()) {
			if(isReplacing)
				states.pop();
		}
		states.push(newState);
		states.top()->init();
		isAdding = false;
	}
}

shared_ptr<State> StateManager::getActiveState() {
	return states.top();
}