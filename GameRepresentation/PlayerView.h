//
// Created by elias on 21/11/2022.
//
#ifndef MEATBOY_PLAYERVIEW_H
#include "EntityView.h"
#include <SFML/Graphics.hpp>
#define MEATBOY_PLAYERVIEW_H

/// deze class bevat de view van de player
class PlayerView : public EntityView {
public:
	PlayerView(PlayerModel& p, RenderWindow& wi, const string& path);
	/// tekent de player
	void draw() override;
	/// updates de positie van de player en tekent het
	void update() override;
};
#endif //MEATBOY_PLAYERVIEW_H