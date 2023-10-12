#include <GameDev2D.h>
#include "Tween.h"

using namespace GameDev2D;

Tween::Tween(float& reference) :
    m_Reference( reference ),
    m_Elapsed( 0.0f ),
    m_Duration( 0.0f ),
    m_Start( 0.0f ),
    m_Target( 0.0f ),
    m_EasingFunction( Linear::Interpolation ),
    m_IsRunning( false )
{
}

void Tween::OnUpdate(float deltaTime)
{
    if( m_IsRunning )
    {
        if( m_Elapsed < m_Duration )
        {
            m_Elapsed += deltaTime;
            float elapsed = m_Elapsed;
            if( m_Elapsed > m_Duration )
            {
                m_IsRunning = false;
            }
            elapsed = Math::Clamp( elapsed, 0, m_Duration );

            float pct = elapsed / m_Duration;
            m_Reference = m_Start + (m_Target - m_Start) * m_EasingFunction(pct);
        }
    }
}

bool Tween::IsRunning()
{
    return m_IsRunning;
}

void Tween::Start(float target, float duration, float initialDelay, EasingFunction easingFunction)
{
    m_Elapsed = -initialDelay;
    m_Duration = duration;
    m_Start = m_Reference;
    m_Target = target;
    m_EasingFunction = easingFunction;
    m_IsRunning = true;
}

void Tween::Cancel()
{
    m_Elapsed = 0.0f;
    m_Duration = 0.0f;
    m_Start = 0.0f;
    m_Target = 0.0f;
    m_EasingFunction = Linear::Interpolation;
    m_IsRunning = false;
}
