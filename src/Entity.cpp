//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Entity.h"
#include "CoordinateConverter.h"

Entity::Entity() :
m_pView(YI_NULL),
m_isCollidable(true)
{
    
}

void Entity::SetView(CYISceneView* view)
{
    m_pView = view;
}

void Entity::SetPosition(YI_INT32 x, YI_INT32 y)
{
    //store our new position
    m_x = x;
    m_y = y;
    
    //convert it to screen space.
    YI_FLOAT convX = static_cast<YI_FLOAT>(CoordinateConverter::CoordinateToPixels(x));
    YI_FLOAT convY = static_cast<YI_FLOAT>(CoordinateConverter::CoordinateToPixels(y));
    
    //set the position of our view.
    m_pView->SetPosition(convX, convY, 0);
}
