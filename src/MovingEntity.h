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
    void Move(YI_INT32 x, YI_INT32 y);
    
protected:
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();

};

#endif /* Entity_h */
