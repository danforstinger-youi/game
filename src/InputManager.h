//
//  InputManager.hpp
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

class InputManager : public CYIEventHandler
{
public:
    InputManager(CYIApp* pApp);
    
    static InputManager* GetInstance();
    
    CYISignal<YI_KEY_CODE> OnKeyDown;
    CYISignal<YI_KEY_CODE> OnKeyUp;
    CYISignal<YI_KEY_CODE> OnKey;
    
protected:
    virtual bool HandleEvent (const CYISharedPtr< CYIEventDispatcher > &pDispatcher, CYIEvent *pEvent);
    
private:
    static InputManager* s_pInstance;
    
};

#endif /* InputManager_hpp */
