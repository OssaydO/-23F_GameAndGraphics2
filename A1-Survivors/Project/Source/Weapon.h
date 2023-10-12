#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Enemy;
class Game;

class Weapon
{
public:
    Weapon(Game* pGame);
    virtual ~Weapon();

    virtual void Reset() = 0;
    virtual void OnUpdate(float deltaTime) = 0;
    virtual void OnRender(BatchRenderer& batchRenderer, bool drawDebugData) = 0;
    virtual void HandleCollisions(EnemyList& enemyList) = 0;
    virtual void LevelUp() = 0;

protected:
    Game* m_pGame;
};
