#pragma once

#include "Easing.h"

using namespace GameDev2D;

class Tween
{
public:
    Tween(float& reference);

    void OnUpdate(float deltaTime);

    bool IsRunning();

    void Start(float target, float duration, float initialDelay, EasingFunction easingFunction = Linear::Interpolation);
    void Cancel();

    void ChangeTarget(float newTarget) { m_Target = newTarget; }

private:
    float& m_Reference;
    float m_Elapsed;
    float m_Duration;
    float m_Start;
    float m_Target;
    EasingFunction m_EasingFunction;
    bool m_IsRunning;
};
