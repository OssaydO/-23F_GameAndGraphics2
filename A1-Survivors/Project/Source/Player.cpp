#include "Player.h"

using namespace GameDev2D;

const float Player::c_Speed = 150.0f; // Pixels per second.
const float Player::c_PickupRadius = 100.0f; // Pixels.
const float Player::c_StartingHealth = 100.0f;

Player::Player(Game* pGame)
    : m_PickupRadius( c_PickupRadius )
    , m_Health( c_StartingHealth )
{
    m_Active = true;
    
    m_Radius = 20.0f;
    
    m_pSprite = new Sprite( "knight_run_anim_f1" );

    m_pSprite->SetAnchor( 0.5f, 0.5f );
    m_pSprite->SetScale( 4.0f, 4.0f );
}

Player::~Player()
{
    delete m_pSprite;
}

void Player::OnUpdate(float deltaTime)
{
    Vector2 dir = m_Controls.Normalized();    

    // Lock to edges.
    if( m_Position.x < 32.0f )
        m_Position.x = 32.0f;
    if( m_Position.x >= GameDev2D::GetScreenWidth()-32.0f )
        m_Position.x = GameDev2D::GetScreenWidth()-32.0f;
    if( m_Position.y < 32.0f )
        m_Position.y = 32.0f;
    if( m_Position.y >= GameDev2D::GetScreenHeight()-32.0f )
        m_Position.y = GameDev2D::GetScreenHeight()-32.0f;
}

void Player::OnRender(BatchRenderer& batchRenderer, bool drawDebugData)
{
    m_pSprite->SetPosition( m_Position );
    batchRenderer.RenderSprite( m_pSprite );
}

void Player::OnKeyEvent(KeyCode keyCode, KeyState keyState)
{
    if( keyState == KeyState::Down )
    {
        if( keyCode == KeyCode::Left || keyCode == KeyCode::A )
            m_Controls.x -= 1;
        if( keyCode == KeyCode::Right || keyCode == KeyCode::D )
            m_Controls.x += 1;
    }

    if( keyState == KeyState::Up )
    {
        if( keyCode == KeyCode::Left )
            m_Controls.x += 1;
    }
}

void Player::OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY)
{
}

void Player::OnMouseMovedEvent(float mouseX, float mouseY)
{
}

void Player::HandleCollision(Vector2 collisionPoint, Vector2 collisionNormal)
{
}
