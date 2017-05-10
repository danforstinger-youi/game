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
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();

    void Move(YI_INT32 x, YI_INT32 y);

};

#endif /* Entity_h */
