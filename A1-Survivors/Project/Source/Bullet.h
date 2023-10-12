#pragma once

#include <GameDev2D.h>
#include "GameObject.h"

using namespace GameDev2D;

class Bullet : public GameObject
{
private:
    static const Color c_Color;
    static const float c_Speed;

public:
    Bullet(Game* pGame);
    virtual ~Bullet();

    virtual void OnUpdate(float deltaTime) override;

    // Getters.
    
    // Setters.
    void SetDirection(Vector2 dir) { m_Direction = dir; }

private:
    Vector2 m_Direction = Vector2(0,0);
};
