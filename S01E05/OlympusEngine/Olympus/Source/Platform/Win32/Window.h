#pragma once

#include "SubObject.h"

namespace Win32 {

	class OLYMPUS_API Window : public Win32::SubObject {

	public:
		Window(std::wstring className, std::wstring classTitle, HICON icon, INT width, INT height);
		~Window();

		virtual VOID Initialize() override;

	protected:
		INT				m_Width;
		INT				m_Height;
	};

}