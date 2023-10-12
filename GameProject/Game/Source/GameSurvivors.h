#pragma once
#include "Framework.h"

class GameSurvivors : public fw::GameCore
{
public:
	GameSurvivors(fw::FWCore* pFW);
	virtual ~GameSurvivors();

	virtual void OnKeyDown(int keyCode) override;
	virtual void OnKeyUp(int keyCode) override;
	virtual void Update(float deltaTime) override;
	virtual void Draw() override;

protected:
	fw::ShaderProgram* m_pWhiteShader = nullptr;
	fw::Mesh m_LinesMesh;
	bool m_MeshIsVisible = true;
};
