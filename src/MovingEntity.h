//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef MovingEntity_h
#define MovingEntity_h

#include "Entity.h"

class MovingEntity : public Entity
{
public:
    bool AttemptMove(YI_INT32 x, YI_INT32 y);
    bool AttemptMove(YI_INT32 x, YI_INT32 y, Entity* out_collider);
    
    virtual void TakeDamage(YI_INT32 damage);
    
protected:
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();

    YI_INT32 hp;
    
    YI_INT32 damage;
};

#endif /* Entity_h */
