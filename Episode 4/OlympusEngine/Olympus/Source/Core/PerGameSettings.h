#pragma once

class OLYMPUS_API PerGameSettings {

private:
	/* Singleton reference to static class */
	static PerGameSettings* inst;

	static PerGameSettings* Instance() { return inst; }

public:
	/* Constructor with Singlton assignment and predefined variables */
	PerGameSettings();
	~PerGameSettings();

private:
	/* Per Game Private Variables */
	WCHAR m_GameName[MAX_NAME_STRING];
	WCHAR m_ShortName[MAX_NAME_STRING];
	HICON m_MainIcon;
	WCHAR m_BootTime[MAX_NAME_STRING];

public:
	/* Access Getters and Setters */
	static WCHAR* GameName() { return inst->m_GameName; }
	static VOID SetGameName(UINT id) { LoadString(HInstance(), id, inst->m_GameName, MAX_NAME_STRING); }

	static WCHAR* ShortName() { return inst->m_ShortName; }
	static VOID SetShortName(UINT id) { LoadString(HInstance(), id, inst->m_ShortName, MAX_NAME_STRING); }

	static HICON MainIcon() { return inst->m_MainIcon; }
	static VOID SetMainIcon(UINT id) { LoadIcon(HInstance(), MAKEINTRESOURCE(id)); }

	static WCHAR* BootTime() { return inst->m_BootTime; }
};