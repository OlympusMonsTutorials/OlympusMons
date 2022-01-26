#include "BlankProject.h"
#include "Engine/Simulation.h"
#include "Platform/WIN32/WinEntry.h"

class BlankProject : public Olympus::Simulation {

	// BlankProject

public:
	/* BlankProject Constuctor */
	BlankProject() {}

	/* BlankProject Deconstructor */
	~BlankProject() {}


public:

	VOID SetupPerGameSettings();

	/* Called to Initialize the BlankProject  */
	VOID Initialize() {}



	/* Game Loop - Called on a loop while the BlankProject is running */
	VOID Update() {}
};
ENTRYAPP(BlankProject)

VOID BlankProject::SetupPerGameSettings()
{
	/* Set the Per Game Settings */
	PerGameSettings::SetGameName(IDS_PERGAMENAME);
	PerGameSettings::SetShortName(IDS_SHORTNAME);
	PerGameSettings::SetMainIcon(IDI_MAINICON);
	PerGameSettings::SetSplashURL(IDS_SPLASHURL);
}



