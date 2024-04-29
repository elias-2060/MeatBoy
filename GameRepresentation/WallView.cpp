//
// Created by elias on 21/11/2022.
//
#include "WallView.h"

WallView::WallView(WallModel& w, RenderWindow& wi, const char* path)
	: EntityView(w, wi) {
	if(!texture.loadFromFile(path)) {
		throw "file not found";
	}
	entity.setTexture(&texture);
	entity.setTextureRect(IntRect(0, 50, entityModel.getWidth(), entityModel.getHeight()));
	entity.setSize(Vector2f(entityModel.getWidth(), entityModel.getHeight()));
	pair<float, float> newPos = entityModel.getWorld().getCamera().coordinateToPixel(
		entityModel.getPositionX(), entityModel.getPositionY(), entityModel);

	entity.setPosition(newPos.first, newPos.second);
}

void WallView::draw() {
	window.draw(entity);
}

void WallView::update() {
	pair<float, float> newPos = entityModel.getWorld().getCamera().coordinateToPixel(
		entityModel.getPositionX(), entityModel.getPositionY(), entityModel);
	entity.setPosition(newPos.first, newPos.second);
	draw();
}
