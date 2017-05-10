//
//  Level.h
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef Level_h
#define Level_h

#include <vector>
#include "Player.h"
#include "Wall.h"
#include "Monster.h"

#include <view/YiSceneView.h>

using std::vector;

class Level
{
public:
    
    Level(CYISceneView *pSceneView);
    
    void Init();
    
    void MovePlayer(int xMovement, int yMovement);
    
    void GenerateLevel();
    
    glm::vec3 IncrementX(glm::vec3 position);
    glm::vec3 ResetX(glm::vec3 position);
    
    glm::vec3 IncrementY(glm::vec3 position);
    
    void CreateWall(glm::vec3 position);
    void CreateMonster(glm::vec3 position);
    void CreatePlayer(glm::vec3 position);
    
    Player* GetPlayer() { return m_pPlayer; }
    
    void AddEntityToLevel(Entity* entity);
    
    void RemoveEntityFromLevel(Entity* entity);
    
    std::vector<Entity*> GetEntitiesAtPosition(YI_INT32 posX, YI_INT32 posY);
    
    std::vector<Entity*> CheckCollisionAtPos(YI_INT32 posX, YI_INT32 posY);
private:
    
    CYISceneView *m_pSceneView;
    Player *m_pPlayer;

    std::vector<Entity*> m_levelEntities;
};
#endif /* Level_h */
