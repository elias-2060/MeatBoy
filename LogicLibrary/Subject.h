//
// Created by elias on 29/11/2022.
//

#ifndef MEATBOY_SUBJECT_H
#include "Observer.h"
#include "memory"
#include "shared_mutex"
#define MEATBOY_SUBJECT_H
using namespace std;

class Subject {
private:
	shared_ptr<Observer> observer;

public:
	/// add een observer to the subject
	void addObserver(shared_ptr<Observer> o);
	/// updates de observer, zodat het op de screen word laten zien
	void updateObserver();
};
#endif // MEATBOY_SUBJECT_H
