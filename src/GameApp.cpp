// © You i Labs Inc. 2000-2017. All rights reserved.
#include "GameApp.h"

#include <animation/YiTimeline.h>
#include <scenetree/YiSceneManager.h>
#include <view/YiSceneView.h>
#include <appium/YiWebDriverLocator.h>

/*! \addtogroup Game
@{
*/
static const CYIString LOG_TAG("GameApp");

GameApp::GameApp()
: m_pSpinAnimation(YI_NULL)
{
}

GameApp::~GameApp()
{
}

bool GameApp::UserInit()
{
//! [UserInit]
    // Start the web driver for allowing the use of appium.
    CYIWebDriver *pWebDriver = CYIWebDriverLocator::GetWebDriver();
    if (pWebDriver)
    {
        pWebDriver->Start();
    }
    
    // Load the MainComp CYISceneView. This is the main scene view for this sample application. The main scene view is loaded here in the CYIApp subclass due to the simplicity of this application.
    // Larger applications would have seperate screens each containing a main scene view with the loading handled by the screen's CYIAbstractScreenViewController subclass.
    CYISceneView *pSceneViewMain = GetSceneManager()->LoadScene("Game_MainComp.layout", CYISceneManager::SCALE_FIT, CYISceneManager::V_ALIGN_CENTER, CYISceneManager::H_ALIGN_CENTER);
    
    if(!pSceneViewMain)
    {
        YI_ASSERT(false, LOG_TAG, "Loading scene 'Game_MainComp.layout' failed.");
        return false;
    }
    
    // Add the scene to the SceneManager with a layer index of 0, since this is the only scene the layer index isn't important.
    GetSceneManager()->AddScene("MainComp", pSceneViewMain, 0, CYISceneManager::LAYER_OPAQUE);

    // Get the SpinAnimation timeline from the main composition and cache it for later use.
    m_pSpinAnimation = pSceneViewMain->GetTimeline("SpinAnimation");
    if(!m_pSpinAnimation)
    {
        YI_ASSERT(false, LOG_TAG, "Failed to find 'SpinAnimation' timeline.");
        return false;
    }

    // Connect to the CompletedForward signal to restart the animation when it completes.
    m_pSpinAnimation->CompletedForward.Connect(*this, &GameApp::OnSpinAnimationCompleted, YI_CONNECTION_ASYNC);
    
    // Start playing the timeline in a forward direction.
    m_pSpinAnimation->StartForward();
    
    return true;

//! [UserInit]
}

bool GameApp::UserStart()
{
    return true;
}

void GameApp::OnSpinAnimationCompleted()
{
    // Timeline has ended. Restart the animation for a continuous loop.
    m_pSpinAnimation->StartForward();
    
}

/*! @} */
