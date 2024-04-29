//
// Created by elias on 29/11/2022.
//
#ifndef MEATBOY_OBSERVER_H
#include "memory"
#include "shared_mutex"
#define MEATBOY_OBSERVER_H

class EntityModel;
class Subject;

class Observer {
public:
	virtual void update() = 0;
};

class EntityObserver : public Observer {
protected:
	EntityModel& entityModel;

public:
	explicit EntityObserver(EntityModel& e);
};

#endif // MEATBOY_OBSERVER_H
