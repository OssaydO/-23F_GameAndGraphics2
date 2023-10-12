#pragma once

#include <GameDev2D.h>
#include "Tween.h"

using namespace GameDev2D;

class Pickup : public GameObject
{
private:
    static const float c_Size; // Pixels.
    static const Color c_Color;

public:
    Pickup(Game* pGame);
    virtual ~Pickup();

    virtual void OnUpdate(float deltaTime) override;
    virtual void OnRender(BatchRenderer& batchRenderer, bool drawDebugData) override;

    void PickupObject(Vector2 destPos);
    bool IsAnimating() { return m_Animating; }

    // Getters.

    // Setters.

private:
    bool m_Animating = false;

    Tween m_TweenPosX;
    Tween m_TweenPosY;
};
