#pragma once

#include <GameDev2D.h>
#include "GameObject.h"
#include "Tween.h"

using namespace GameDev2D;

class Enemy : public GameObject
{
private:
    static const float c_StartingHealth;
    static const float c_Speed;
    static const float c_AnimSpeed;

public:
    Enemy(Game* pGame);
    virtual ~Enemy();

    virtual void OnUpdate(float deltaTime) override;
    virtual void OnRender(BatchRenderer& batchRenderer, bool drawDebugData) override;

    void StartDeathAnim();
    bool IsFadingOut() { return m_FadingOut; }

    // Getters.
    float GetHealth() { return m_Health; }

    // Setters.
    void ApplyDamage(float damage);
    void SetHealth(float health) { m_Health = health; }
    void SetActive(bool active) override;

private:
    float m_Health = 0.0f;

    Sprite* m_pSprites[2] = {};
    float m_AnimTimer = 0;
    int m_CurrentFrame = 0;

    bool m_FadingOut = false;

    float m_VisibleScale = 0.0f;

    Tween m_TweenSize;
};
