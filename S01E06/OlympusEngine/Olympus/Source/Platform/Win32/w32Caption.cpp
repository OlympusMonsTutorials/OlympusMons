#include "Olympus.h"
#include "w32Caption.h"

namespace Win32 {
    VOID Caption::AddCaptionButton(CaptionButton* button)
    {
        m_CaptionButtons.push_back(button);
    }
}
