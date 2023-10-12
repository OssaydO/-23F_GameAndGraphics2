#pragma once

namespace fw {

class FWCore;

class GameCore
{
public:
    GameCore(FWCore* pFW);
    virtual ~GameCore();

    virtual void OnKeyDown(int keyCode) = 0;
    virtual void OnKeyUp(int keyCode) = 0;
    virtual void Update(float deltaTime) = 0;
    virtual void Draw() = 0;

protected:
    FWCore* m_pFW = nullptr;
};

} // namespace fw
