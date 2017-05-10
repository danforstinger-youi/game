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
    bool GetIsCollidable() { return m_isCollidable; }
    void SetIsCollidable(bool isCollidable) { m_isCollidable = isCollidable; }
    
    void Destroy();
    
    virtual void TakeDamage(YI_INT32 damage) { YI_UNUSED(damage);}
protected:
    
    bool bIsActive = true;
    
    CYISceneView* m_pView;

private:
    
    YI_INT32 m_x;
    YI_INT32 m_y;
    bool m_isCollidable;
};

#endif /* Entity_h */
