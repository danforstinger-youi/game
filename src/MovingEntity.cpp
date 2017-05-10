//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "MovingEntity.h"

bool MovingEntity::Init()
{
    return true;
}

void MovingEntity::Move(YI_INT32 x, YI_INT32 y)
{
    YI_INT32 newX = GetX() + x;
    YI_INT32 newY = GetY() + y;
    
    SetPosition(newX,newY);
}
