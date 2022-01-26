#pragma once
#include <string>

namespace Time {

	/* Get current time in string format */
	WSTRING OLYMPUS_API GetTime(BOOL stripped = FALSE);

	/* Get current date in string format */
	WSTRING OLYMPUS_API GetDate(BOOL stripped = FALSE);

	/* Get current date and time in string format */
	WSTRING OLYMPUS_API GetDateTimeString(BOOL stripped = FALSE);
}