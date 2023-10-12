#pragma once

#include <GameDev2D.h>
#include "Weapon.h"

using namespace GameDev2D;

class Bullet;

class Weapon_Gun : public Weapon
{
private:
    static const int c_NumBullets;
    static const int c_BulletDamage;
    static const float c_InitialBulletSpawnTime;
    static const float c_BulletSpawnTimeDecreasePerLevel;

public:
    Weapon_Gun(Game* pGame);
    virtual ~Weapon_Gun();

    virtual void Reset() override;
    virtual void OnUpdate(float deltaTime) override;
    virtual void OnRender(BatchRenderer& batchRenderer, bool drawDebugData) override;
    virtual void HandleCollisions(EnemyList& enemyList) override;
    virtual void LevelUp() override;

    void SpawnBullet(Vector2 pos);

private:
    std::vector<Bullet*> m_Bullets;

    float m_CurrentBulletSpawnTime = 0.0f;
    float m_BulletSpawnTimer = 0.0f;
};
