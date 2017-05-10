//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Entity_h
#define Entity_h

#include "view/YiSceneView.h"

class Entity : public CYISceneView
{
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();
    
    YI_TYPE_BASES(Entity, CYISceneView);
};

#endif /* Entity_h */
