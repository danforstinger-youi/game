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
    
    void MovePlayer(int xMovement, int yMovement);
    
    void GenerateLevel();
    
    glm::vec3 IncrementX(glm::vec3 position);
    glm::vec3 ResetX(glm::vec3 position);
    
    glm::vec3 IncrementY(glm::vec3 position);
    
    void CreateWall(glm::vec3 position);
    void CreateMonster(glm::vec3 position);
    void CreatePlayer(glm::vec3 position);
    
private:
    CYISceneView *m_pSceneView;
    Player *m_pPlayer;
    
    vector<Wall*> walls;

};
#endif /* Level_h */
