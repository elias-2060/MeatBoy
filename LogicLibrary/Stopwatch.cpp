//
// Created by elias on 11/12/2022.
//
#include "Stopwatch.h"

Stopwatch::Stopwatch() {
	prevTime = chrono::steady_clock::now();
	deltaTime = 0;
	timeMultiplier = 60;
}

shared_ptr<Stopwatch> Stopwatch::getStopwatch() {
	if(stopwatch == nullptr) {
		stopwatch = shared_ptr<Stopwatch>(new Stopwatch);
	}
	return stopwatch;
}

void Stopwatch::nextFrame() {
	auto currTime = chrono::steady_clock::now();
	chrono::duration<float> timeDiff = currTime - prevTime;
	deltaTime = timeDiff.count();
	prevTime = currTime;
}

float Stopwatch::getTimeMultiplier() const {
	return deltaTime * timeMultiplier;
}
