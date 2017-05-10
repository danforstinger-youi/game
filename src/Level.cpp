//
//  Level.cpp
//  Game
//
//  Created by David Delisle-Lalancette on 2017-05-10.
//
//

#include "Level.h"
#include "GameApp.h"
#include <glm/glm.hpp>
#include "Constants.h"
#include "EntityFactory.h"

Level::Level(CYISceneView *pSceneView)
{
    m_pSceneView = pSceneView;

    GenerateLevel();
}

void Level::MovePlayer(int xMovement, int yMovement)
{
    m_pPlayer->AttemptMove(xMovement, yMovement);
}

void Level::GenerateLevel()
{
    char tileCharacter = 0;
    
    const char *path = "assets/level.txt";

    std::FILE *pFile = std::fopen(path, "r");
    YI_ASSERT(pFile, "Level::Level", "Could not open %s", "level.txt");
    
    std::fstream levelFile(path);
    
    std::stringstream buffer;
    buffer << levelFile.rdbuf();
    std::string contents(buffer.str());
    
    glm::vec3 position(0, 0, 0);
    
    bool playerPlaced = false;
    
    size_t index = 0;
    while(index < contents.length())
    {
        tileCharacter = contents[index];
    
        switch (tileCharacter)
        {
            default: case '\n':
                position = IncrementY(ResetX(position));
                break;
            case '#':
                CreateWall(position);
                position = IncrementX(position);
                break;
            case ' ':
                position = IncrementX(position);
                break;
            case 'X':
                CreateMonster(position);
                position = IncrementX(position);
                break;
            case '@':
                if(!playerPlaced)
                {
                    CreatePlayer(position);
                    position = IncrementX(position);
                    playerPlaced = true;
                }
                break;
        }
        
        ++index;
    }

}

glm::vec3 Level::IncrementX(glm::vec3 position)
{
    glm::vec3 result(position[0] + 1, position[1], 0);
    return result;
}

glm::vec3 Level::ResetX(glm::vec3 position)
{
    glm::vec3 result(0, position[1], 0);
    return result;
}

glm::vec3 Level::IncrementY(glm::vec3 position)
{
    glm::vec3 result(position[0], position[1] + 1, 0);
    return result;
}

void Level::CreateWall(glm::vec3 position)
{
    EntityFactory::Instantiate<Wall>(WALL_PREFAB_NAME, m_pSceneView, position[0], position[1]);
}

void Level::CreateMonster(glm::vec3 position)
{
    EntityFactory::Instantiate<Monster>(MONSTER_PREFAB_NAME, m_pSceneView, position[0], position[1]);}

void Level::CreatePlayer(glm::vec3 position)
{
    m_pPlayer = EntityFactory::Instantiate<Player>(PLAYER_PREFAB_NAME, m_pSceneView, position[0], position[1]);
}
