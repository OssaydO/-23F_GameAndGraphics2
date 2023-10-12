#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Enemy;
class Pickup;
class Player;
class Weapon;

class Game
{
private:
    static const int c_NumEnemies;
    static const int c_NumPickups;
    static const int c_InitialXPRequiredToLevelUp;
    static const float c_XPMultiplierPerLevel;
    static const float c_InitialEnemySpawnTime;

public:
    Game();
    virtual ~Game();

    void Reset();
    void OnUpdate(float deltaTime);
    void OnRender(BatchRenderer& batchRenderer);

    // Input event methods.
    void OnKeyEvent(KeyCode keyCode, KeyState keyState);
    void OnMouseButtonEvent(MouseButton button, MouseButtonState state, float mouseX, float mouseY);
    void OnMouseMovedEvent(float mouseX, float mouseY);

    void SpawnEnemies();
    void SpawnEnemy(Vector2 pos);
    void SpawnPickup(Vector2 pos);

    void HandleCollisions();
    void HandleXP();

    void OnEnemyKilled(Vector2 location);
    Enemy* GetClosestEnemy(Vector2 pos);

    // Getters.
    Player* GetPlayer() { return m_pPlayer; }
    bool IsGameOver() { return m_GameOver; }

private:
    SpriteFont m_Font;

    bool m_GameOver = false;
    int m_EnemiesKilled = 0;
    int m_ExperiencePoints = 0;
    float m_TimePlayed = 0.0f;

    int m_CurrentXPRequiredToLevelUp = 0;
    float m_EnemySpawnTimer = 0.0f;

    bool m_DrawDebugData = false;
    
    Sprite* m_pBG = nullptr;
    Player* m_pPlayer = nullptr;
    std::vector<Weapon*> m_Weapons;
    EnemyList m_Enemies;
    std::vector<Pickup*> m_Pickups;
};
