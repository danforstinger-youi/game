//
//  Level.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Level.h"
#include "GameApp.h"
#include <glm/glm.hpp>


using glm::vec3;

Level::Level(Player *pPlayer)
{
    m_pPlayer = pPlayer;
    
    int squareWidth = 7;
    
    vec3 initialPosition(0, 0, 0);
    
    
    for (int x = 0; x < squareWidth; ++x)
    {
        int minY = 0;
        int maxY = squareWidth-1;
        
        //Build the wall
        YI_UNUSED(minY);
        YI_UNUSED(maxY);
        //SetPosition->(
    }
    
    for (int y = 1; y < squareWidth - 1; ++y)
    {
        int minX = 0;
        int maxX = squareWidth-1;
        
        YI_UNUSED(minX);
        YI_UNUSED(maxX);
    }
}
