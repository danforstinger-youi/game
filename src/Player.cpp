//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Player.h"
#include "GameApp.h"
#include "TurnManager.h"
#include "InputManager.h"

bool Player::Init()
{
    MovingEntity::Init();
    
    YI_LOGI("Player", "Init complete");

    InputManager::GetInstance()->OnKeyDown.Connect(*this, &Player::OnKey);
    
    return true;
}

void Player::OnKey(YI_KEY_CODE keyCode)
{
    YI_LOGI("Player::OnKey", "Count %d", keyCode);
    
    bool bDidMove = false;
    
    switch (keyCode)
    {
        case YI_KEY_ARROW_LEFT:
            bDidMove = AttemptMove(-1,0);
            break;
            
        case YI_KEY_ARROW_RIGHT:
            bDidMove = AttemptMove(1,0);
            break;
            
        case YI_KEY_ARROW_UP:
            bDidMove = AttemptMove(0,-1);
            break;
            
        case YI_KEY_ARROW_DOWN:
            bDidMove = AttemptMove(0,1);
            break;
            
        default:
            break;
    }
    
    if (bDidMove)
    {
        GameApp::GetTurnManager()->FinishTurn();
    }

}
