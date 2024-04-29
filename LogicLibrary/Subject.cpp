//
// Created by elias on 29/11/2022.
//
#include "Subject.h"

void Subject::addObserver(shared_ptr<Observer> o) {
	observer = std::move(o);
}

void Subject::updateObserver() {
	observer->update();
}
