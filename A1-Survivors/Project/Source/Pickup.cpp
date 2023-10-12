#include "Pickup.h"
#include "Game.h"
#include "Player.h"

using namespace GameDev2D;

const float Pickup::c_Size = 10.0f; // Pixels.
const Color Pickup::c_Color = ColorList::Blue;

Pickup::Pickup(Game* pGame)
    : GameObject( pGame )
    , m_TweenPosX( m_Position.x )
    , m_TweenPosY( m_Position.y )
{
    m_Active = false;

    m_Position.Set( 0, 0 );
    m_Radius = c_Size;
}

Pickup::~Pickup()
{
}

void Pickup::OnUpdate(float deltaTime)
{
    m_TweenPosX.ChangeTarget( m_pGame->GetPlayer()->GetPosition().x );
    m_TweenPosY.ChangeTarget( m_pGame->GetPlayer()->GetPosition().y );
    
    m_TweenPosX.OnUpdate( deltaTime );
    m_TweenPosY.OnUpdate( deltaTime );
    
    if( m_Animating && m_TweenPosX.IsRunning() == false && m_TweenPosY.IsRunning() == false )
    {
        m_Animating = false;
        SetActive( false );
    }
}

void Pickup::OnRender(BatchRenderer& batchRenderer, bool drawDebugData)
{
    batchRenderer.RenderCircle( m_Position, m_Radius/2, c_Color, ColorList::Black, 2 );
}

void Pickup::PickupObject(Vector2 destPos)
{
    m_Animating = true;

    m_TweenPosX.Start( destPos.x, 0.5f, 0.0f, Back::In );
    m_TweenPosY.Start( destPos.y, 0.5f, 0.0f, Back::In );
}
