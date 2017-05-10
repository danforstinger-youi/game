//
//  InputManager.cpp
//  Game
//
//  Created by Brad Hill on 2017-05-10.
//
//

#include <event/YiEventDispatcher.h>
#include <framework/YiAppContext.h>
#include <scenetree/YiSceneManager.h>
#include "event/YiKeyEvent.h"
#include "GameApp.h"

#include "InputManager.h"

InputManager* InputManager::s_pInstance = YI_NULL;

InputManager::InputManager(CYIApp* pApp)
{
    if(s_pInstance != YI_NULL)
    {
        YI_ASSERT(false, "InputManager", "Attempting to create multiple instances of event manager");
    }
    
    s_pInstance = this;
    
    pApp->GetSceneManager()->AddGlobalEventListener(YI_KEY_DOWN, this);
    pApp->GetSceneManager()->AddGlobalEventListener(YI_KEY_UP, this);
}

InputManager* InputManager::GetInstance()
{
    return s_pInstance;
}

bool InputManager::HandleEvent (const CYISharedPtr< CYIEventDispatcher > &pDispatcher, CYIEvent *pEvent)
{
    YI_UNUSED(pDispatcher);
    
    if(pEvent->IsKeyEvent())
    {
        CYIKeyEvent* keyEvent = static_cast<CYIKeyEvent*>(pEvent);
        YI_KEY_CODE keyCode = keyEvent->m_eKeyCode;
        
        OnKey(keyEvent->m_eKeyCode);
        
        if(keyEvent->GetType() == YI_KEY_UP && IsKeyDown(keyCode))
        {
            OnKeyUp(keyCode);
            SetKeyUp(keyCode);
        }
        else if(keyEvent->GetType() == YI_KEY_DOWN && !IsKeyDown(keyCode))
        {
            OnKeyDown(keyCode);
            SetKeyDown(keyCode);
        }
        else
        {
            OnKey(keyCode);
        }
        
        return true;
    }
    
    return false;
}

void InputManager::SetKeyDown(YI_KEY_CODE keyCode)
{
    m_downKeys.insert(keyCode);
}

bool InputManager::IsKeyDown(YI_KEY_CODE keyCode)
{
    return m_downKeys.count(keyCode) > 0;
}

void InputManager::SetKeyUp(YI_KEY_CODE keyCode)
{
    m_downKeys.erase(keyCode);
}
