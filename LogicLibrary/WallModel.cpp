//
// Created by elias on 23/11/2022.
//
#include "WallModel.h"

WallModel::WallModel(World& w, float x, float y, float wi, float h)
	: EntityModel(w, wallModel) {
	positionX = x;
	positionY = y;
	width = wi;
	height = h;
}
