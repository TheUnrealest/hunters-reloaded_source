// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ModuleManager.h"
#include "IInputDeviceModule.h"

DECLARE_LOG_CATEGORY_EXTERN(JoyShockPlugin, Display, All);

class FJoyShockPluginModule : public IInputDeviceModule
{
public:

	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FJoyShockPluginModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FJoyShockPluginModule >("JoyShockPlugin");
	}

	/**
	* Checks to see if this module is loaded and ready.  It is only valid to call Get() if IsAvailable() returns true.
	*
	* @return True if the module is loaded and ready to use
	*/
	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("JoyShockPlugin");
	}


	virtual TSharedPtr< class IInputDevice > CreateInputDevice(const TSharedRef< FGenericApplicationMessageHandler >& InMessageHandler);

	//virtual void StartupModule() override; // This is not required as IInputDeviceModule handels it!
	virtual void ShutdownModule() override;

	TSharedPtr< class FJoyShockPluginDevice > JoyShockPluginDevice;

private:
	void* ExampleLibraryHandle;
};