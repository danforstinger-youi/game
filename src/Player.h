//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Player_h
#define Player_h

#include "MovingEntity.h"
#include "view/YiSceneView.h"
#include <signal/YiSignalHandler.h>

class Player : public MovingEntity, public CYISignalHandler
{
public:
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init();
    
protected:
    void OnKey(YI_KEY_CODE keyCode);
};

#endif /* Player_h */
