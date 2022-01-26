#pragma once 

class OLYMPUS_API OEngine;
namespace Engine {

	enum  EngineMode : INT {
		NONE,
		DEBUG,
		RELEASE,
		EDITOR,
		SERVER
	};

	extern OEngine g_OlympusEngine;

	VOID OLYMPUS_API SetMode(EngineMode mode);
	EngineMode OLYMPUS_API GetMode();

	WSTRING OLYMPUS_API EngineModeToString();

}

using namespace Engine;
class OLYMPUS_API OEngine {

public:
	OEngine();
	~OEngine();

private:
	EngineMode m_EngineMode;

public:
	EngineMode GetEngineMode();
	VOID SetEngineMode(EngineMode mode);

};
