//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Monster.h"
#include "GameApp.h"
#include "TurnManager.h"
#include "Level.h"
#include "Player.h"

bool Monster::Init()
{
    GameApp::GetTurnManager()->BeginTurn.Connect(*this, &Monster::TakeTurn);
    
    damage = 4;
    hp = 7;
    
    return true;
}

void Monster::TakeTurn()
{
    Player* pPlayer = GameApp::GetLevel()->GetPlayer();
    
    YI_INT32 x = GetX();
    YI_INT32 y = GetY();
    
    YI_INT32 playerX = pPlayer->GetX();
    YI_INT32 playerY = pPlayer->GetY();
    
    YI_INT32 xDiff = abs(x - playerX);
    YI_INT32 yDiff = abs(y - playerY);
    
    //check distance to determine if we should move.
    if (xDiff + yDiff > ACTIVATION_DIST) return;
    
    YI_INT32 xMove = 0;
    YI_INT32 yMove = 0;
    
    if (xDiff > yDiff)
    {
        if (x < playerX) xMove = 1;
        else xMove = -1;
    }
    else
    {
        if (y < playerY) yMove = 1;
        else yMove = -1;
    }
    
    AttemptMove(xMove, yMove);
}
