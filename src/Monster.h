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
#include "signal/YiSignalHandler.h"

class Monster: public MovingEntity, public CYISignalHandler
{
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();

private:
    
    void TakeTurn();
};

#endif /* Entity_h */
