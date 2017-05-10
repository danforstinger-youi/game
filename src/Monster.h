//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Monster_h
#define Monster_h

#include "MovingEntity.h"

class Monster: public MovingEntity
{
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();
};

#endif /* Entity_h */
