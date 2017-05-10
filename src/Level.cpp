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
#include "Constants.h"
#include "EntityFactory.h"

Level::Level(CYISceneView *pSceneView)
{
    m_pSceneView = pSceneView;
    
    int squareWidth = 7;
    
    glm::vec3 initialPosition(0, 0, 0);
    glm::vec3 playerStartingPosition(3, 3, 3);
    
    for (int x = 0; x < squareWidth; ++x)
    {
        int minY = 0;
        int maxY = squareWidth-1;
        
        Wall *upperWall = EntityFactory::Instantiate<Wall>(WALL_PREFAB_NAME, pSceneView, initialPosition[0]+x, minY);
        walls.insert(walls.end(), upperWall);
        
        Wall *lowerWall = EntityFactory::Instantiate<Wall>(WALL_PREFAB_NAME, pSceneView, initialPosition[0]+x, maxY);
        walls.insert(walls.end(), lowerWall);

    }
    
    for (int y = 1; y < squareWidth - 1; ++y)
    {
        int minX = 0;
        int maxX = squareWidth-1;
        
        Wall *leftWall = EntityFactory::Instantiate<Wall>(WALL_PREFAB_NAME, pSceneView, minX, initialPosition[1]+y);
        walls.insert(walls.end(), leftWall);

        
        Wall *rightWall = EntityFactory::Instantiate<Wall>(WALL_PREFAB_NAME, pSceneView, maxX, initialPosition[1]+y);
        walls.insert(walls.end(), rightWall);

    }
    
    m_pPlayer = EntityFactory::Instantiate<Player>(PLAYER_PREFAB_NAME, pSceneView, playerStartingPosition[0], playerStartingPosition[1]);
}

void Level::MovePlayer(int xMovement, int yMovement)
{
    m_pPlayer->AttemptMove(xMovement, yMovement);
}
