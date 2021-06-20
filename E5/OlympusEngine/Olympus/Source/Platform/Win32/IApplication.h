#pragma once

#define ENTRYAPP(x) Win32::IApplication* EntryApplication() { return new x; }

namespace Win32 {

	class OLYMPUS_API IApplication {

		// Application

	public:
		/* Application Constuctor */
		IApplication();

		/* Application Deconstructor */
		virtual ~IApplication() {};


	public:

		/* Called to setup our pergame settings  */
		virtual VOID SetupPerGameSettings() = 0;

		/* Called to Initialize the Application  */
		virtual VOID PreInitialize() = 0;

		/* Called to Initialize the Application  */
		virtual VOID Initialize() = 0;

		/* Game Loop - Called on a loop while the Application is running */
		virtual VOID Update() = 0;
	};

	IApplication* EntryApplication();
}