//
// Created by elias on 23.12.22.
//
#include "GoalModel.h"

GoalModel::GoalModel(World& w, float x, float y)
	: EntityModel(w, goalModel) {
	positionX = x;
	positionY = y;
	width = 30;
	height = 30;
}
