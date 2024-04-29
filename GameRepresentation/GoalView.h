//
// Created by elias on 23.12.22.
//

#ifndef MEATBOY_GOALVIEW_H
#include "EntityView.h"
#include <SFML/Graphics.hpp>
#define MEATBOY_GOALVIEW_H
using namespace sf;
using namespace std;

/// bevat de view van de goal
class GoalView : public EntityView {
public:
	GoalView(GoalModel& g, RenderWindow& wi, const char* path);
	/// tekent de goal
	void draw() override;
	/// updates de positie van de goal en tekent het
	void update() override;
};

#endif // MEATBOY_GOALVIEW_H
