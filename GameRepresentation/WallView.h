//
// Created by elias on 21/11/2022.
//
#ifndef MEATBOY_WALLVIEW_H
#include "EntityView.h"
#include <SFML/Graphics.hpp>
#define MEATBOY_WALLVIEW_H

/// bevat de view van de wall
class WallView : public EntityView {
public:
	WallView(WallModel& w, RenderWindow& wi, const char* path);
	/// tekent de wall
	void draw() override;
	/// updates de positie van de wall en tekent het
	void update() override;
};

#endif //MEATBOY_WALLVIEW_H
