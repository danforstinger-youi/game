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

    void SetPosition(YI_INT32 x, YI_INT32 y);
    
    YI_INT32 GetX() { return m_x;}
    
    YI_INT32 GetY() { return m_y;}
    
protected:
    
    CYISceneView* m_pView;

private:
    
    YI_INT32 m_x;
    
    YI_INT32 m_y;
};

#endif /* Entity_h */
