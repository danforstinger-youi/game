//
//  Entity.hpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#ifndef TurnManager_h
#define TurnManager_h

#include "view/YiSceneView.h"

class TurnManager
{
public:
    
    TurnManager();
    
    void FinishTurn();
    
    CYISignal<> BeginTurn;

};

#endif /* Wall_h */
