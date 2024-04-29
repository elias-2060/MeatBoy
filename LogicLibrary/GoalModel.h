//
// Created by elias on 23.12.22.
//

#ifndef MEATBOY_GOALMODEL_H
#include "EntityModel.h"
#define MEATBOY_GOALMODEL_H

/// deze class bevat de data van de goal
class GoalModel : public EntityModel {
public:
	GoalModel(World& w, float x, float y);
};

#endif // MEATBOY_GOALMODEL_H
