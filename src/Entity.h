//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Entity_h
#define Entity_h

#include <view/YiSceneView.h>

class Entity
{
public:
    
    Entity();

    void SetView(CYISceneView* view);
    
    /*!
     \details This will be called during initialization, this is where custom views will initialize themselves.
     */
    virtual bool Init() = 0;

protected:
    
    CYISceneView* m_pView;
};

#endif /* Entity_h */
