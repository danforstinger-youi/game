//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "MovingEntity.h"

#include <glm/glm.hpp>
#include "GameApp.h"

bool MovingEntity::Init()
{
    return true;
}

bool MovingEntity::AttemptMove(YI_INT32 x, YI_INT32 y)
{
    return AttemptMove(x, y, YI_NULL);
}

bool MovingEntity::AttemptMove(YI_INT32 x, YI_INT32 y, Entity* out_collider)
{
    if (!bIsActive) return false;
    
    YI_INT32 newX = GetX() + x;
    YI_INT32 newY = GetY() + y;
    
    std::vector<Entity*> colliders = GameApp::GetLevel()->CheckCollisionAtPos(newX, newY);
    
    if(colliders.size() > 0)
    {
        colliders.at(0)->TakeDamage(damage);
        YI_LOGE("MovingEntity", "Entity has collided!");
        if(out_collider == YI_NULL)
        {
            out_collider = colliders.at(0);
            
        }
        return false;
    }
    
    
    
    SetPosition(newX, newY);
    
    YI_LOGE("MovingEntity", "Entity has moved!");
    return true;
}

void MovingEntity::TakeDamage(YI_INT32 damage)
{
    YI_LOGE("MovingEntity", "Entity has taken %d damage", damage);
    
    hp -= damage;
    
    if (hp <= 0)
    {
        Destroy();
    }
}
