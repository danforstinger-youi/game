//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Entity.h"

Entity::Entity() : m_pView(YI_NULL)
{
    
}

void Entity::SetView(CYISceneView* view)
{
    m_pView = view;
}
