//
//  InputManager.h
//  Game
//
//  Created by Brad Hill on 2017-05-10.
//
//

#ifndef InputManager_hpp
#define InputManager_hpp

#include <framework/YiApp.h>
#include <event/YiEventHandler.h>
#include <signal/YiSignal.h>
#include <unordered_set>

class InputManager : public CYIEventHandler
{
public:
    InputManager(CYIApp* pApp);
    //virtual ~InputManager();
    
    static InputManager* GetInstance();
    
    CYISignal<YI_KEY_CODE> OnKeyDown;
    CYISignal<YI_KEY_CODE> OnKeyUp;
    CYISignal<YI_KEY_CODE> OnKey;
    
    virtual bool HandleEvent(const CYISharedPtr<CYIEventDispatcher> &pDispatcher, CYIEvent *pEvent);
    
private:
    static InputManager* s_pInstance;
    std::unordered_set<YI_KEY_CODE, std::hash<int> > m_downKeys;
    
    void SetKeyDown(YI_KEY_CODE keyCode);
    bool IsKeyDown(YI_KEY_CODE keyCode);
    void SetKeyUp(YI_KEY_CODE keyCode);
};

#endif /* InputManager_h */
