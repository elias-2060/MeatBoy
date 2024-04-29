//
// Created by elias on 27/11/2022.
//
#include "EntityModel.h"

EntityModel::EntityModel(World& w)
	: world(w) {
	type = undefined;
}
EntityModel::EntityModel(World& w, EntityType t)
	: world(w) {
	type = t;
}

World& EntityModel::getWorld() {
	return world;
}

float EntityModel::getWidth() const {
	return width;
}

float EntityModel::getHeight() const {
	return height;
}

float EntityModel::getPositionX() const {
	return positionX;
}

float EntityModel::getPositionY() const {
	return positionY;
}

bool EntityModel::checkCollision(EntityModel& p, EntityModel& w) {
	float pMinX = min(p.getPositionX(), p.getPositionX() + p.getWidth());
	float pMaxX = max(p.getPositionX(), p.getPositionX() + p.getWidth());
	float pMinY = min(p.getPositionY(), p.getPositionY() + p.getHeight());
	float pMaxY = max(p.getPositionY(), p.getPositionY() + p.getHeight());

	float wMinX = min(w.getPositionX(), w.getPositionX() + w.getWidth());
	float wMaxX = max(w.getPositionX(), w.getPositionX() + w.getWidth());
	float wMinY = min(w.getPositionY(), w.getPositionY() + w.getHeight());
	float wMaxY = max(w.getPositionY(), w.getPositionY() + w.getHeight());

	float interLeft = max(pMinX, wMinX);
	float interTop = max(pMinY, wMinY);
	float interRight = min(pMaxX, wMaxX);
	float interBottom = min(pMaxY, wMaxY);
	if((interLeft <= interRight) && (interTop <= interBottom)) {
		/// player heeft collision van onder en wall collision van boven
		if(wMaxY > pMinY && pMaxY > wMaxY && pMaxX != wMinX && pMinX != wMaxX) {
			p.setCollisionBottom(true);
			p.setCollisionTop(false);

			w.setCollisionRight(false);
			w.setCollisionLeft(false);
			w.setCollisionBottom(false);
			w.setCollisionTop(true);
		}
		/// player heeft collision van boven en wall collision van onder
		else if(pMinY < wMinY && pMaxY > wMinY) {
			p.setCollisionRight(false);
			p.setCollisionLeft(false);
			p.setCollisionTop(true);

			w.setCollisionRight(false);
			w.setCollisionLeft(false);
			w.setCollisionBottom(true);
			w.setCollisionTop(false);
		}
		/// player heeft collision van links en wall collision van rechts
		else if(wMinX < pMinX && pMaxX > wMaxX && pMinY != wMaxY) {
			p.setCollisionLeft(true);
			p.setCollisionRight(false);
			p.setCollisionTop(false);

			w.setCollisionRight(true);
			w.setCollisionLeft(false);
			w.setCollisionBottom(false);
			w.setCollisionTop(false);
		}
		/// player heeft collision van rechts en wall collision van links
		else if(wMaxX > pMinX && pMinX < wMinX && pMinY != wMaxY) {
			p.setCollisionRight(true);
			p.setCollisionLeft(false);
			p.setCollisionTop(false);

			w.setCollisionRight(false);
			w.setCollisionLeft(true);
			w.setCollisionBottom(false);
			w.setCollisionTop(false);
		}
		return true;
	}
	return false;
}

bool EntityModel::getCollisionLeft() const {
	return collisionLeft;
}

bool EntityModel::getCollisionRight() const {
	return collisionRight;
}

bool EntityModel::getCollisionTop() const {
	return collisionTop;
}

bool EntityModel::getCollisionBottom() const {
	return collisionBottom;
}

void EntityModel::setCollisionLeft(bool l) {
	collisionLeft = l;
}

void EntityModel::setCollisionRight(bool r) {
	collisionRight = r;
}

void EntityModel::setCollisionTop(bool t) {
	collisionTop = t;
}

void EntityModel::setCollisionBottom(bool b) {
	collisionBottom = b;
}
