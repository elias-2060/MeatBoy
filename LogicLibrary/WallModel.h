//
// Created by elias on 23/11/2022.
//

#ifndef MEATBOY_WALLMODEL_H
#include "EntityModel.h"
#define MEATBOY_WALLMODEL_H

/// deze class bevat de data van de wall
class WallModel : public EntityModel {
public:
	WallModel(World& w, float x, float y, float width, float height);
};

#endif // MEATBOY_WALLMODEL_H
