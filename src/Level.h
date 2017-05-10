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

#include <view/YiSceneView.h>

using std::vector;

class Level
{
public:
    
    Level(CYISceneView *pSceneView);
    
    void Init();
    
    void MovePlayer(int xMovement, int yMovement);
    
    Player* GetPlayer() { return m_pPlayer; }
    
    void AddEntityToLevel(Entity* entity);
    
    std::vector<Entity*> GetEntitiesAtPosition(YI_INT32 posX, YI_INT32 posY);
    
    std::vector<Entity*> CheckCollisionAtPos(YI_INT32 posX, YI_INT32 posY);
private:
    
    CYISceneView *m_pSceneView;
    Player *m_pPlayer;
    
    vector<Wall*> walls;

    std::vector<Entity*> m_levelEntities;
};
#endif /* Level_h */
