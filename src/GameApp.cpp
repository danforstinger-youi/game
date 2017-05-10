// © You i Labs Inc. 2000-2017. All rights reserved.
#include "GameApp.h"

#include <animation/YiTimeline.h>
#include <scenetree/YiSceneManager.h>
#include <view/YiSceneView.h>
#include <appium/YiWebDriverLocator.h>
#include "Player.h"
#include "EntityFactory.h"
#include <asset/YiAssetViewTemplate.h>
#include <import/YiViewTemplate.h>
#include <view/YiImageView.h>
#include "InputManager.h"

static const CYIString LOG_TAG("GameApp");

GameApp::GameApp()
{
    m_pInstance = this;
    m_pTurnManager = new TurnManager();
}

GameApp::~GameApp()
{
    delete m_pSceneViewMain;
    m_pSceneViewMain = YI_NULL;
    
    delete m_pTurnManager;
    m_pTurnManager = YI_NULL;
    
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
    m_pSceneViewMain = GetSceneManager()->LoadScene("Game_MainComp.layout", CYISceneManager::SCALE_FIT, CYISceneManager::V_ALIGN_CENTER, CYISceneManager::H_ALIGN_CENTER);
    
    if(!m_pSceneViewMain)
    {
        YI_ASSERT(false, LOG_TAG, "Loading scene 'Game_MainComp.layout' failed.");
        return false;
    }
    
    m_pInputManager = new InputManager(this);
    
    // Add the scene to the SceneManager with a layer index of 0, since this is the only scene the layer index isn't important.
    GetSceneManager()->AddScene("MainComp", m_pSceneViewMain, 0, CYISceneManager::LAYER_OPAQUE);
    
    m_pLevel = new Level(m_pSceneViewMain);

    return true;

//! [UserInit]
}

bool GameApp::UserStart()
{
    return true;
}

TurnManager* GameApp::GetTurnManager()
{
    return m_pInstance->m_pTurnManager;
}

/*! @} */
