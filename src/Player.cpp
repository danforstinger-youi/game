//
//  Entity.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Player.h"

#include "InputManager.h"

bool Player::Init()
{
    InputManager::GetInstance()->OnKey.Connect(*this, &Player::OnKey);
    
    return true;
}

void Player::OnKey(YI_KEY_CODE keyCode)
{
    YI_LOGI("Player::OnKey", "Count %d", keyCode);
}
