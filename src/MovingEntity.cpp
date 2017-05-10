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

void MovingEntity::Move(YI_INT32 x, YI_INT32 y)
{
    glm::vec3 position = m_pView->GetPosition();
    
    SetPosition(position[0] + x, position[1] + y);
}
