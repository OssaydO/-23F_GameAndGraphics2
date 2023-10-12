#include "Bullet.h"

using namespace GameDev2D;

const Color Bullet::c_Color = ColorList::Green;
const float Bullet::c_Speed = 5500.0f;

Bullet::Bullet(Game* pGame)
    : GameObject( pGame )
{
    m_Radius = 10.0f;
}

Bullet::~Bullet()
{
}

void Bullet::OnUpdate(float deltaTime)
{
    Vector2 velocity = m_Direction * c_Speed;
    m_Position += velocity * deltaTime;

    // TODO: If the bullet goes off screen, deactivate it.
}
