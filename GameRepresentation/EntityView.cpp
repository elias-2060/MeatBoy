//
// Created by elias on 29/11/2022.
//
#include "EntityView.h"
EntityView::EntityView(EntityModel& m, RenderWindow& w)
	: EntityObserver(m)
	, window(w) { }
