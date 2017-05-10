//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Wall_h
#define Wall_h

#include "view/YiSceneView.h"
#include "Entity.h"

class Wall : public CYISceneView, public Entity
{
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();
};

#endif /* Wall_h */
