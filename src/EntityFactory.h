//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef EntityFactory_h
#define EntityFactory_h

#include <view/YiSceneView.h>
#include <asset/YiAssetViewTemplate.h>
#include <import/YiViewTemplate.h>
#include "Entity.h"

class EntityFactory
{
public:
    /*!
     \details This can be used to create entities.
     */
    template <class T>
    static T* Instantiate(const CYIString& name, CYISceneView* surface)
    {
        
        T* controller = new T();
        
        Entity* entity = static_cast<Entity*>(controller);
        
        if (!entity)
        {
            YI_ASSERT(false, "Entity Factory", "Passed in type is not an entity. Instantiation failed.");
            
        }
        
        const CYISharedPtr<CYIAssetViewTemplate> pTemplate = CYIViewTemplate::GetViewTemplate(name);
        
        CYISceneView* pPrefab = pTemplate->BuildView(surface->GetSceneManager());
        
        surface->AddChild(pPrefab);
        
        entity->SetView(pPrefab);
        
        entity->Init();
        
        return controller;
    }
};

#endif /* Entity_h */
