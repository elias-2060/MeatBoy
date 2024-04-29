//
// Created by elias on 21/11/2022.
//
#include "PlayerModel.h"
#include "World.h"

PlayerModel::PlayerModel(World& w, float x, float y)
	: EntityModel(w, playerModel) {
	positionX = x;
	positionY = y;
	initVariables();
}

void PlayerModel::move(float dirX, float dirY) {
	/// Jumping
	if(dirY > 0)
		velocityY = jumpForce;
	if(dirY < 0)
		velocityY += dirY;

	/// Acceleration
	velocityX += dirX * acceleration;

	/// Limit velocity
	if(abs(velocityX) > velocityMax) {
		velocityX = velocityMax * ((velocityX < 0) ? -1.f : 1.f);
	}

	if(dirY != 0 && dirX == 0)
		update(true);
	else if(dirX != 0 && dirY == 0)
		update(false);
	else {
		update(false);
		update(true);
	}
}

void PlayerModel::initVariables() {
	width = 30;
	height = 30;
	velocityX = 0;
	velocityY = 0;
	addDrag = false;
	drag = 0.1;
	velocityMax = 5.5;
	acceleration = 0.3;
	gravity = 0.2;
	groundHeight = 0;
	jumpForce = 6;
	isJumping = false;
	isMovingLeft = false;
	isMovingRight = false;
	isStillJumping = false;
}

void PlayerModel::update(bool jump) {
	float nextPosX = positionX;
	float nextPosY = positionY;
	if(jump)
		nextPosY += velocityY * world.getStopwatch()->getTimeMultiplier();
	else {
		nextPosX += velocityX * world.getStopwatch()->getTimeMultiplier();
	}

	// left side collision
	if(nextPosX < 0) {
		nextPosX = 0;
	}
	// right side collision
	if(nextPosX > world.getCamera().getWindowWidth() - width) {
		nextPosX = world.getCamera().getWindowWidth() - width;
	}

	// floor collision
	if(nextPosY < 0)
		nextPosY = 0;

	positionX = nextPosX;
	positionY = nextPosY;
}

void PlayerModel::resetVel() {
	if(!isStillJumping or collisionRight or collisionLeft) {
		velocityX = 0;
	}
}

void PlayerModel::checkJump() {
	if(positionY > groundHeight) {
		move(0, -gravity);
		isStillJumping = true;
	}
	if(positionY == groundHeight) {
		velocityY = 0;
		isStillJumping = false;
	}
	if(positionY == 0) {
		collisionBottom = false;
	}
}

float PlayerModel::getGroundHeight() const {
	return groundHeight;
}

void PlayerModel::setIsJumping(bool j) {
	isJumping = j;
}

bool PlayerModel::getIsJumping() const {
	return isJumping;
}

void PlayerModel::setAddDrag(bool d) {
	addDrag = d;
}

void PlayerModel::checkDrag() {
	/// als de player in de lucht is dan addDrag
	if(addDrag) {
		if(positionY == groundHeight) {
			addDrag = false;
			velocityX = 0;
		} else if(velocityX < 0) {
			velocityX += drag;
			update(false);
		} else if(velocityX > 0) {
			velocityX -= drag;
			update(false);
		}
	}
}

void PlayerModel::setIsMovingLeft(bool m) {
	isMovingLeft = m;
}

bool PlayerModel::getIsMovingLeft() const {
	return isMovingLeft;
}

void PlayerModel::setIsMovingRight(bool m) {
	isMovingRight = m;
}

bool PlayerModel::getIsMovingRight() const {
	return isMovingRight;
}

void PlayerModel::setIsStillJumping(bool j) {
	isStillJumping = j;
}

bool PlayerModel::getIsStillJumping() const {
	return isStillJumping;
}

void PlayerModel::checkCollisionWalls(const vector<shared_ptr<WallModel>>& walls) {
	bool tempBottom = false;
	bool tempLeft = false;
	bool tempRight = false;
	bool tempTop = false;
	for(auto& wall : walls) {
		if(checkCollision(*this, *wall)) {
			if(collisionBottom) {
				if(wall->getCollisionTop()) {
					if(!wall->getCollisionLeft() and !wall->getCollisionRight()) {
						positionY = wall->getPositionY() + wall->getHeight();
						groundHeight = wall->getPositionY() + wall->getHeight();
						tempBottom = true;
					}
				}
			}
			if(collisionRight) {
				if(wall->getCollisionLeft()) {
					positionX = wall->getPositionX() - width;
					tempRight = true;
				}
			}
			if(collisionLeft) {
				if(wall->getCollisionRight()) {
					positionX = wall->getPositionX() + wall->getWidth();
					tempLeft = true;
				}
			}
			if(collisionTop) {
				if(wall->getCollisionBottom()) {
					move(0, -gravity);
					positionY = wall->getPositionY() - height;
					checkJump();
					tempTop = true;
				}
			}
		} else {
			wall->setCollisionLeft(false);
			wall->setCollisionRight(false);
			wall->setCollisionBottom(false);
			wall->setCollisionTop(false);
		}
		addDrag = true;
	}
	if(!tempBottom) {
		groundHeight = 0;
	}
	if(!tempLeft) {
		collisionLeft = false;
	}
	if(!tempRight) {
		collisionRight = false;
	}
	if(!tempTop) {
		collisionTop = false;
	}
}

void PlayerModel::setGroundHeight(float h) {
	groundHeight = h;
}
