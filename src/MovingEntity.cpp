//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "MovingEntity.h"

#include <glm/glm.hpp>

bool MovingEntity::Init()
{
    return true;
}

bool MovingEntity::AttemptMove(YI_INT32 x, YI_INT32 y)
{
    YI_INT32 newX = GetX() + x;
    YI_INT32 newY = GetY() + y;
    
    SetPosition(newX,newY);
    
    YI_LOGE("MovingEntity", "Entity has moved!");
    return true;
}
