// © You i Labs Inc. 2000-2017. All rights reserved.
#ifndef _GAME_APP_H_
#define _GAME_APP_H_

#include <framework/YiApp.h>
#include <signal/YiSignalHandler.h>
#include "TurnManager.h"
#include "Entity.h"
#include "Level.h"

class CYISceneView;

/*!
 \defgroup Game Game
 \brief This basic sample displays a rotating image.
 
 \details <H3>Purpose:</H3>
 To demonstrate how to load a simple view and and to manually trigger animations.
 <H3>Suggested Learning Activities:</H3>
 Modify the animation in the After Effects file (Game.aep), export the composition using the You.i Engine Affect Effects plugin and launch the application to view the changes.

 */
/*@{*/

class InputManager;

class GameApp : public CYIApp, public CYISignalHandler
{
public:
    GameApp();
    
    virtual ~GameApp();
    
    /*!
        \details Pure virtual of CYIApp.
        \sa CYIApp::UserInit
     */
    virtual bool UserInit();
    /*!
        \details Pure virtual of CYIApp.
        \sa CYIApp::UserStart
     */
    virtual bool UserStart();

    static TurnManager* GetTurnManager();
    
    static Level* GetLevel();
    
    static CYISceneView* GetSceneView() { return m_pInstance->m_pSceneViewMain; }
    
private:
    
    static GameApp * m_pInstance;
    
    TurnManager * m_pTurnManager;
    
    CYISceneView * m_pSceneViewMain;
    
    Level *m_pLevel;

    InputManager* m_pInputManager;
};

/*!
 @}
*/

#endif //_HELLO_WORLD_APP_H_
