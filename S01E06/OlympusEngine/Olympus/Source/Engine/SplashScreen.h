#pragma once

#include "Platform/Win32/Window.h"

namespace SplashScreen {



	VOID OLYMPUS_API Open();
	VOID OLYMPUS_API Close();
	VOID OLYMPUS_API AddMessage(CONST WCHAR* message);

}

class OLYMPUS_API SplashWindow : public Win32::Window {

public:
	SplashWindow();
	~SplashWindow();

	virtual			LRESULT				MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) override;

private:
	WCHAR m_outputMessage[MAX_NAME_STRING];
};