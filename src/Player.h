//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Player_h
#define Player_h

#include "view/YiSceneView.h"
#include "Entity.h"

class Player : public Entity
{
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();

};

#endif /* Player_h */
