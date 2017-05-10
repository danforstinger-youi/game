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

using std::vector;

class Level
{
    Player *m_pPlayer;
    
    vector<Wall*> walls;
    
public:
    Level(Player *pPlayer);
    
    void MovePlayer(int xMovement, int yMovement);
};
#endif /* Level_h */
