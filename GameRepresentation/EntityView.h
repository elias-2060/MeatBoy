//
// Created by elias on 29/11/2022.
//

#ifndef MEATBOY_ENTITYVIEW_H
#include "../LogicLibrary/EntityModel.h"
#include "../LogicLibrary/World.h"
#include <SFML/Graphics.hpp>
#define MEATBOY_ENTITYVIEW_H
using namespace sf;

/// virtual class van de view van de entity
class EntityView : public EntityObserver {
protected:
	RenderWindow& window;
	EntityView(EntityModel& m, RenderWindow& w);
	Texture texture;
	RectangleShape entity;

public:
	/// tekent de entity
	virtual void draw() = 0;
};
#endif //MEATBOY_ENTITYVIEW_H
