//
// Created by elias on 23.12.22.
//
#include "GoalView.h"

GoalView::GoalView(GoalModel& g, RenderWindow& wi, const char* path)
	: EntityView(g, wi) {
	if(!texture.loadFromFile(path)) {
		throw "file not found";
	}
	entity.setTexture(&texture);
	entity.setSize(Vector2f(entityModel.getWidth(), entityModel.getHeight()));
	pair<float, float> newPos = entityModel.getWorld().getCamera().coordinateToPixel(
		entityModel.getPositionX(), entityModel.getPositionY(), entityModel);
	entity.setPosition(newPos.first, newPos.second);
}

void GoalView::draw() {
	window.draw(entity);
}

void GoalView::update() {
	pair<float, float> newPos = entityModel.getWorld().getCamera().coordinateToPixel(
		entityModel.getPositionX(), entityModel.getPositionY(), entityModel);
	entity.setPosition(newPos.first, newPos.second);
	draw();
}
