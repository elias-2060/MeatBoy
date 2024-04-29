//
// Created by elias on 22.12.22.
//

#ifndef MEATBOY_STATEMANAGER_H
#include "State.h"
#include "memory"
#include "shared_mutex"
#include "stack"
#define MEATBOY_STATEMANAGER_H

using namespace std;

/// deze class bevat de states in een stack, en handles de state transitions
class StateManager {
private:
	stack<shared_ptr<State>> states;
	shared_ptr<State> newState;
	bool isRemoving;
	bool isAdding;
	bool isReplacing;

public:
	StateManager();
	~StateManager();
	/// add een state op de stack, met een bool replacing als het de current top moet replacen
	void addState(shared_ptr<State> newState, bool isReplacing = true);
	/// verweiderd een state
	void removeState();
	/// handles de state changes (add a state or delete a state)
	void processStateChanges();
	/// returned de top van de stack (de current active state)
	shared_ptr<State> getActiveState();
};

#endif //MEATBOY_STATEMANAGER_H
