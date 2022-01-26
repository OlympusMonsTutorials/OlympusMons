#include "Olympus.h"
#include "Window.h"

namespace Win32 {

	Window::Window(std::wstring className, std::wstring classTitle, HICON icon, INT width, INT height)
		: Win32::SubObject(className,classTitle,icon), m_Width(width), m_Height(height)
	{

	}

	Window::~Window()
	{

	}

	VOID Window::Initialize()
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);

		RECT R = { 0, 0, m_Width, m_Height };
		AdjustWindowRect(&R, WS_OVERLAPPEDWINDOW, false);
		int width = R.right - R.left;
		int height = R.bottom - R.top;

		m_Handle = CreateWindow(m_Class.c_str(), m_Title.c_str(),
			WS_POPUP, ((desktop.right / 2) - (m_Width / 2)), ((desktop.bottom / 2) - (m_Height / 2)), m_Width, m_Height, 0, 0, HInstance(), (void*)this);

		ShowWindow(m_Handle, SW_SHOW);
		UpdateWindow(m_Handle);

	}

}
