#pragma once

#define DEFAULTWIDTH 800
#define DEFAULTHEIGHT 600

namespace Win32 {

    enum WindowType : DWORD {
       STATIC       =   WS_OVERLAPPED,
       RESIZABLE    =   WS_SIZEBOX,
       POPUP        =   WS_POPUP
    };

    

    namespace Utils {

        BOOL OLYMPUS_API AddBitmap(CONST WCHAR* szFileName, HDC hWinDC, INT x = 0, INT y = 0);

        /// Sets and clears style flags for a particular window.
        inline VOID OLYMPUS_API ModifyWindowStyle(HWND hWnd, DWORD flagsToDisable, DWORD flagsToEnable)
        {
            DWORD style = GetWindowLong(hWnd, GWL_STYLE);
            SetWindowLong(hWnd, GWL_STYLE, (style & ~flagsToDisable) | flagsToEnable);
        }

        /// Sets and clears extended style flags for a particular window.
        inline VOID OLYMPUS_API ModifyWindowExStyle(HWND hWnd, DWORD flagsToDisable, DWORD flagsToEnable)
        {
            DWORD exStyle = GetWindowLong(hWnd, GWL_EXSTYLE);
            SetWindowLong(hWnd, GWL_EXSTYLE, (exStyle & ~flagsToDisable) | flagsToEnable);
        }


        inline BOOL OLYMPUS_API HasStyle(HWND hwnd, DWORD style) {
            DWORD dwStyle = (DWORD)GetWindowLong(hwnd, GWL_STYLE);
            if ((dwStyle & style) != 0) return TRUE;
            return FALSE;
        }


        /// Sets and clears style flags for a particular window.
        inline VOID OLYMPUS_API ModifyClassStyle(HWND hWnd, DWORD flagsToDisable, DWORD flagsToEnable)
        {
            DWORD style = GetWindowLong(hWnd, GCL_STYLE);
            SetClassLong(hWnd, GCL_STYLE, (style & ~flagsToDisable) | flagsToEnable);
        }

        inline BOOL OLYMPUS_API IsWindowFullscreen(HWND hWnd)
        {
            WINDOWPLACEMENT placement;
            GetWindowPlacement(hWnd, &placement);

            if (placement.showCmd == SW_MAXIMIZE)
                return TRUE;
            return FALSE;
        }

        inline VOID OLYMPUS_API MaximizeWindow(HWND hwnd) {
            WINDOWPLACEMENT wPos;
            GetWindowPlacement(hwnd, &wPos);
            if (wPos.showCmd == SW_MAXIMIZE) ShowWindow(hwnd, SW_NORMAL);
            else  ShowWindow(hwnd, SW_MAXIMIZE);
        }

    }
}