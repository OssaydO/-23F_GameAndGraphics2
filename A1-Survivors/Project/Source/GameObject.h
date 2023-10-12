#pragma once

#include <GameDev2D.h>

using namespace GameDev2D;

class Game;

class GameObject
{
public:
    GameObject(Game* pGame);
    virtual ~GameObject();

    virtual void Reset();
    virtual void OnUpdate(float deltaTime);
    virtual void OnRender(BatchRenderer& batchRenderer, bool drawDebugData);
    virtual bool IsCollidingWithGameObject(GameObject* pOtherObject);

    // Getters.
    bool IsActive()       { return m_Active; }
    Vector2 GetPosition() { return m_Position; }
    float GetAngle()      { return m_Angle; }
    float GetRadius()     { return m_Radius; }
    Color GetColor()      { return m_Color; }

    // Setters.
    virtual void SetActive(bool active) { m_Active = active; }
    void SetPosition(Vector2 pos) { m_Position = pos; }
    void SetAngle(float angle)    { m_Angle = angle; }
    void SetRadius(float radius)  { m_Radius = radius; }
    void SetColor(Color color)    { m_Color = color; }

protected:
    bool m_Active = false;
    
    Game* m_pGame = nullptr;
    Vector2 m_Position = Vector2(0,0);
    float m_Angle = 0;
    float m_Radius = 0;
    Color m_Color = ColorList::White;
};
