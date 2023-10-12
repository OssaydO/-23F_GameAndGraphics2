#pragma once

#include <GameDev2D.h>
#include "GameObject.h"

using namespace GameDev2D;

class Player : public GameObject
{
private:
    static const float c_Speed; // Pixels per second.
    static const float c_PickupRadius; // Pixels.
    static const float c_StartingHealth;

public:
    Player(Game* pGame);
    virtual ~Player();

    virtual void OnUpdate(float deltaTime) override;
    virtual void OnRender(BatchRenderer& batchRenderer, bool drawDebugData) override;

    // Input event methods.
    void OnKeyEvent(KeyCode keyCode, KeyState keyState);
    void OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY);
    void OnMouseMovedEvent(float mouseX, float mouseY);

    void HandleCollision(Vector2 collisionPoint, Vector2 collisionNormal);

    // Getters.
    float GetHealth() { return m_Health; }
    float GetPickupRadius() { return m_PickupRadius; }

private:
    float m_Health = 0;
    float m_PickupRadius = 0;

    Sprite* m_pSprite = nullptr;
    Vector2 m_Controls = Vector2(0,0);
};
