#include "Olympus.h"

namespace Engine {

	OEngine g_OlympusEngine;

	VOID SetMode(EngineMode mode)
	{
		g_OlympusEngine.SetEngineMode(mode);
	}


	EngineMode GetMode()
	{
		return g_OlympusEngine.GetEngineMode();
	}

	std::wstring OLYMPUS_API EngineModeToString()
	{
		switch (Engine::GetMode())
		{
		case EngineMode::DEBUG:		return L"Debug";
		case EngineMode::RELEASE:	return L"Release";
		case EngineMode::SERVER:	return L"Server";
		case EngineMode::EDITOR:	return L"Editor";
		default:     return L"None";
		}
	}


}


OEngine::OEngine()
{
#ifdef _DEBUG
	m_EngineMode = EngineMode::DEBUG;
#else
	m_EngineMode = EngineMode::RELEASE;
#endif
}

OEngine::~OEngine()
{
}

EngineMode OEngine::GetEngineMode()
{
	return m_EngineMode;
}

VOID OEngine::SetEngineMode(EngineMode mode)
{
	m_EngineMode = mode;
}


