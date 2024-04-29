//
// Created by elias on 27/11/2022.
//

#ifndef MEATBOY_ENTITYMODEL_H
#include "Subject.h"
#define MEATBOY_ENTITYMODEL_H
using namespace std;

enum EntityType { playerModel, wallModel, goalModel, undefined };

class World;
class EntityObserver;

class EntityModel : public Subject {
protected:
	EntityType type;
	World& world;
	float width = 0.f;
	float height = 0.f;
	float positionX = 0.f;
	float positionY = 0.f;
	bool collisionRight = false;
	bool collisionLeft = false;
	bool collisionTop = false;
	bool collisionBottom = false;
	float groundHeight;
	explicit EntityModel(World& w);
	EntityModel(World& w, EntityType t);

public:
	World& getWorld();
	float getWidth() const;
	float getHeight() const;
	float getPositionX() const;
	float getPositionY() const;
	bool getCollisionLeft() const;
	bool getCollisionRight() const;
	bool getCollisionTop() const;
	bool getCollisionBottom() const;
	void setCollisionLeft(bool l);
	void setCollisionRight(bool r);
	void setCollisionTop(bool t);
	void setCollisionBottom(bool b);
	/// kijkt of er een collision is tussen 2 entities
	bool checkCollision(EntityModel& p, EntityModel& w);
};

#endif // MEATBOY_ENTITYMODEL_H
