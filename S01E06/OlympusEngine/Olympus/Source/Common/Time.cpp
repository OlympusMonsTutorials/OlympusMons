#include "Olympus.h"
#include <ctime>
#include <sstream>
#include <iomanip>

/* Get Time in format '00:00:00' */
/* Stripped = 000000 */
WSTRING Time::GetTime(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%T");

	WSTRING timeString = wss.str();



	if (stripped) {
		WSTRING chars = L":";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}
	return timeString;
}

/* Get date in format '00/00/00' */
/* Stripped = 000000 */
WSTRING Time::GetDate(BOOL stripped)
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	std::wstringstream wss;
	wss << std::put_time(&ltm, L"%d/%m/%y");
	WSTRING timeString = wss.str();

	if (stripped) {
		WSTRING chars = L"/";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}

/* Get date time in format '00/00/00 00:00:00' */
/* Stripped = 000000000000 */
WSTRING Time::GetDateTimeString(BOOL stripped)
{
	WSTRING timeString = GetDate(stripped) + L" " + GetTime(stripped);

	if (stripped) {
		WSTRING chars = L" ";
		for (WCHAR c : chars) {
			timeString.erase(std::remove(timeString.begin(), timeString.end(), c), timeString.end());
		}
	}

	return timeString;
}

