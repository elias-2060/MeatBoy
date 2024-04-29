//
// Created by elias on 21/11/2022.
//

#ifndef MEATBOY_PLAYERMODEL_H
#include "EntityModel.h"
#include "WallModel.h"
#include "shared_mutex"
#include "vector"
#include <memory>
#define MEATBOY_PLAYERMODEL_H

/// deze class bevat de data van de player
class PlayerModel : public EntityModel {
protected:
	float velocityX;
	float velocityY;
	bool addDrag;
	float drag;
	float velocityMax;
	float acceleration;
	float gravity;
	float jumpForce;
	bool isJumping;
	bool isMovingLeft;
	bool isMovingRight;
	bool isStillJumping;

public:
	explicit PlayerModel(World& w, float x, float y);
	/// initialiseerd alle variables
	void initVariables();
	/// updates de velocity van de player
	void move(float dirX, float dirY);
	/// updates de postie van de player met de current velocity
	void update(bool jump);
	/// resets de velocity van de player
	void resetVel();
	/// kijkt of de player jumped, zoja dan add het de gravity op de player
	void checkJump();
	/// returned de current groundHeight waar de player op kan staan
	float getGroundHeight() const;
	/// zegt of de player jumped of niet
	void setIsJumping(bool j);
	/// returned of de player aan het jumpen is of niet
	bool getIsJumping() const;
	/// zegt of er drag bij de velocity van de player moet komen
	void setAddDrag(bool d);
	/// kijkt of er drag moet bij gedaan bij de velocity, zoja dn add ik de drag
	/// bij de player zijn curr velocity
	void checkDrag();
	/// zegt of de player links beweegt
	void setIsMovingLeft(bool m);
	/// returned of de player links beweegt
	bool getIsMovingLeft() const;
	/// zegt of de player rechts beweegt
	void setIsMovingRight(bool m);
	/// returned of de player rechts beweegt
	bool getIsMovingRight() const;
	/// zegt of de player nog altijd aan het jumpen is
	void setIsStillJumping(bool j);
	/// returned of de player nog altijd aan het jumpen is
	bool getIsStillJumping() const;
	/// kijkt of er collision is met de player en alle walls dat er current zijn
	void checkCollisionWalls(const vector<shared_ptr<WallModel>>& walls);
	/// zegt wat de current groundHeight is
	void setGroundHeight(float h);
};
#endif // MEATBOY_PLAYERMODEL_H
