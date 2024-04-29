//
// Created by elias on 21/11/2022.
//
#include "PlayerView.h"

PlayerView::PlayerView(PlayerModel& p, RenderWindow& wi, const string& path)
	: EntityView(p, wi) {
	texture.loadFromFile(path);
	entity.setTexture(&texture);
	entity.setSize(Vector2f(entityModel.getWidth(), entityModel.getHeight()));
	pair<float, float> newPos = entityModel.getWorld().getCamera().coordinateToPixel(
		entityModel.getPositionX(), entityModel.getPositionY(), entityModel);
	entity.setPosition(newPos.first, newPos.second);
}

void PlayerView::draw() {
	window.draw(entity);
}

void PlayerView::update() {
	pair<float, float> newPos = entityModel.getWorld().getCamera().coordinateToPixel(
		entityModel.getPositionX(), entityModel.getPositionY(), entityModel);
	entity.setPosition(newPos.first, newPos.second);
	draw();
}
