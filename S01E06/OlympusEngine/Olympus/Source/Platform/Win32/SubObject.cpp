#include "Olympus.h"
#include "SubObject.h"

namespace Win32 {

	SubObject::SubObject(WSTRING className, WSTRING classTitle, HICON icon)
		: m_Class(className), m_Title(classTitle), m_hIcon(icon)
	{
	}

	SubObject::~SubObject()
	{
	}


	VOID SubObject::RegisterNewClass()
	{
		WNDCLASSEX wcex;
		wcex.cbSize = sizeof(WNDCLASSEX);
		wcex.style = CS_HREDRAW | CS_VREDRAW;
		wcex.cbClsExtra = 0;
		wcex.cbWndExtra = 0;
		wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wcex.hbrBackground = (HBRUSH)(CreateSolidBrush(RGB(36, 36, 36)));
		wcex.hIcon = m_hIcon;
		wcex.hIconSm = m_hIcon;
		wcex.lpszClassName = m_Class.c_str();
		wcex.lpszMenuName = nullptr;
		wcex.hInstance = HInstance();
		wcex.lpfnWndProc = SetupMessageHandler;
		RegisterClassEx(&wcex);
	}


	LRESULT SubObject::SetupMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		if (msg == WM_NCCREATE)
		{
			const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
			Win32::SubObject* const pWnd = static_cast<Win32::SubObject*>(pCreate->lpCreateParams);
			SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
			SetWindowLongPtr(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Win32::SubObject::AssignMessageHandler));
			pWnd->Handle(hWnd);
			return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
		}
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	LRESULT SubObject::AssignMessageHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		Win32::SubObject* const pWnd = reinterpret_cast<Win32::SubObject*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		return pWnd->MessageHandler(hWnd, msg, wParam, lParam);
	}

	LRESULT SubObject::MessageHandler(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		return DefWindowProc(hwnd, message, wParam, lParam);
	}


#pragma endregion

}
