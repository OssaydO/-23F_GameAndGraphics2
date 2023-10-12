#include "GameSurvivors.h"
#include "DataTypes.h"

GameSurvivors::GameSurvivors(fw::FWCore* pFW) : fw::GameCore( pFW )
{
	glClearColor( 0.0f, 0.0f, 0.3f, 1.0f);
	glPointSize( 20 );
	glLineWidth( 5 );

	m_pWhiteShader = new fw::ShaderProgram( "Data/Shaders/Basic.vert", "Data/Shaders/White.frag" );

	std::vector<float> attribs = { 50, 99, 0.5f, 0.5f, 99.5f, 20, 20.5f, 70.5f };
	m_LinesMesh.Create( attribs, GL_TRIANGLES );
}

GameSurvivors::~GameSurvivors()
{
}

void GameSurvivors::OnKeyDown(int keyCode)
{
	if( keyCode == VK_F1 )
	{
		wglSwapInterval( 1 ); // V-Sync on
	}
	if( keyCode == VK_F2 )
	{
		wglSwapInterval( 0 ); // V-Sync off
	}
}

void GameSurvivors::OnKeyUp(int keyCode)
{
	m_MeshIsVisible = true;
}

void GameSurvivors::Update(float deltaTime)
{
}

void GameSurvivors::Draw()
{
	glClear( GL_COLOR_BUFFER_BIT );

	if( m_MeshIsVisible )
	{
		m_LinesMesh.Draw( m_pWhiteShader, vec2(0,0) );
	}

	m_pFW->SwapBuffers();
}
