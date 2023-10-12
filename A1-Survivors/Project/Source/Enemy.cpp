#include "Enemy.h"
#include "Game.h"
#include "Player.h"

using namespace GameDev2D;

const float Enemy::c_StartingHealth = 1.0f;
const float Enemy::c_Speed = 0.0f;
const float Enemy::c_AnimSpeed = 0.3f;

Enemy::Enemy(Game* pGame)
    : GameObject( pGame )
    , m_TweenSize( m_VisibleScale )
    , m_Health( c_StartingHealth )
{
    m_Radius = 20.0f;

    m_pSprites[0] = new Sprite( "fly_anim_f1" );
    m_pSprites[1] = new Sprite( "fly_anim_f2" );

    for( int i=0; i<2; i++ )
    {
        m_pSprites[i]->SetAnchor( 0.5f, 0.5f );
        m_pSprites[i]->SetScale( 4.0f, 4.0f );
    }

    m_AnimTimer = Math::RandomFloat( 0.0f, c_AnimSpeed );
}

Enemy::~Enemy()
{
    delete m_pSprites[0];
    delete m_pSprites[1];
}

void Enemy::OnUpdate(float deltaTime)
{
    m_TweenSize.OnUpdate( deltaTime );

    // Deactivate when tween is finished.
    if( m_FadingOut == true && m_TweenSize.IsRunning() == false )
    {
        m_Active = false;
        return;
    }

    // Move toward player.
    Vector2 dir = m_pGame->GetPlayer()->GetPosition() - m_Position;
    dir.Normalize();

    Vector2 velocity = dir * c_Speed;
    m_Position += velocity * deltaTime;

    // Update animation.
    m_AnimTimer += deltaTime;
}

void Enemy::OnRender(BatchRenderer& batchRenderer, bool drawDebugData)
{
    m_pSprites[m_CurrentFrame]->SetPosition( m_Position );
    m_pSprites[m_CurrentFrame]->SetScale( m_VisibleScale*4.0f, m_VisibleScale*4.0f );
    batchRenderer.RenderSprite( m_pSprites[m_CurrentFrame] );
}

void Enemy::StartDeathAnim()
{
    m_Health = 0.0f;
    m_VisibleScale = 1.0f;
    m_FadingOut = true;

    m_TweenSize.Start( 0.0f, 0.5f, 0.0f, Linear::Interpolation );
}

void Enemy::ApplyDamage(float damage)
{
    m_Health = 0;
    if( m_Health < 0 )
    {
        StartDeathAnim();
    }
}

void Enemy::SetActive(bool active)
{
    GameObject::SetActive( active );
    
    m_VisibleScale = 0.0f;
    m_FadingOut = false;
    m_Health = c_StartingHealth;

    if( m_Active == true )
    {
        m_TweenSize.Start( 1.0f, 1.5f, 0.0f, Elastic::Out );
    }
}
