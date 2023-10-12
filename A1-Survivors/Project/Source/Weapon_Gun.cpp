#include "Weapon_Gun.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"
#include "Player.h"

using namespace GameDev2D;

const int Weapon_Gun::c_NumBullets = 5;
const int Weapon_Gun::c_BulletDamage = 1000;
const float Weapon_Gun::c_InitialBulletSpawnTime = 0.8f;
const float Weapon_Gun::c_BulletSpawnTimeDecreasePerLevel = 0.1f;

Weapon_Gun::Weapon_Gun(Game* pGame)
    : Weapon( pGame )
{
    // Fill a vector with bullets.
    for( int i=0; i<c_NumBullets; i++ )
    {
        Bullet* pBullet = new Bullet( pGame );
        m_Bullets.push_back( pBullet );
    }
}

Weapon_Gun::~Weapon_Gun()
{
    for( Bullet* pBullet : m_Bullets )
    {
        delete pBullet;
    }
}

void Weapon_Gun::Reset()
{
    for( Bullet* pBullet : m_Bullets )
    {
        pBullet->Reset();
    }

    m_CurrentBulletSpawnTime = c_InitialBulletSpawnTime;
    m_BulletSpawnTimer = 0;
}

void Weapon_Gun::OnUpdate(float deltaTime)
{
    for( Bullet* pBullet : m_Bullets )
    {
        if( pBullet->IsActive() )
        {
            pBullet->OnUpdate( deltaTime );
        }
    }

    if( m_pGame->IsGameOver() == false )
    {
        m_BulletSpawnTimer -= deltaTime;
        if( m_BulletSpawnTimer < 0 )
        {
            m_BulletSpawnTimer = m_CurrentBulletSpawnTime;
            SpawnBullet( m_pGame->GetPlayer()->GetPosition() );
        }
    }
}

void Weapon_Gun::OnRender(BatchRenderer& batchRenderer, bool drawDebugData)
{
    for( Bullet* pBullet : m_Bullets )
    {
        if( pBullet->IsActive() )
        {
            pBullet->OnRender( batchRenderer, drawDebugData );
        }
    }
}

void Weapon_Gun::HandleCollisions(EnemyList& enemyList)
{
    // Bullets hitting enemies.
    for( int b=0; b<c_NumBullets; b++ )
    {
        if( m_Bullets[b]->IsActive() )
        {
            Vector2 bulletPos = m_Bullets[b]->GetPosition();
            float bulletRadius = m_Bullets[b]->GetRadius();

            // Check if they collide with any enemies.
            for( size_t e=0; e<enemyList.size(); e++ )
            {
                if( enemyList[e]->IsActive() && enemyList[e]->GetHealth() > 0 )
                {
                    // TODO: When the bullet hits an enemy
                    //     apply damage to the enemy
                    //     deactivate the bullet
                    //     let the game know an enemy was killed (for the xp)
                }        
            }
        }        
    }
}

void Weapon_Gun::SpawnBullet(Vector2 pos)
{
    Bullet* pBullet = nullptr;

    // Find the first inactive Bullet.
    for( int i=0; i<c_NumBullets; i++ )
    {
        if( m_Bullets[i]->IsActive() == false )
        {
            pBullet = m_Bullets[i];
            break;
        }
    }

    // Active the Bullet and send it toward the closest enemy.
    if( pBullet )
    {
        Vector2 playerPos = m_pGame->GetPlayer()->GetPosition();
        Enemy* nearestEnemy = m_pGame->GetClosestEnemy( playerPos );
        if( nearestEnemy )
        {
            pBullet->SetActive( true );
            pBullet->SetPosition( pos );

            Vector2 enemyPos = nearestEnemy->GetPosition();
            Vector2 dir = (enemyPos - playerPos).Normalized();
            pBullet->SetDirection( dir );
        }
    }
}

void Weapon_Gun::LevelUp()
{
    m_CurrentBulletSpawnTime -= c_BulletSpawnTimeDecreasePerLevel;
}
