#include "GameObject.h"

using namespace GameDev2D;

GameObject::GameObject(Game* pGame)
    : m_pGame( pGame )
{
}

GameObject::~GameObject()
{
}

void GameObject::Reset()
{
}

void GameObject::OnUpdate(float deltaTime)
{
}

void GameObject::OnRender(BatchRenderer& batchRenderer, bool drawDebugData)
{
}

bool GameObject::IsCollidingWithGameObject(GameObject* pOtherObject)
{
    return false;
}
