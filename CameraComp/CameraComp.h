
#ifndef _CameraComp_COMPONENT_H
#define _CameraComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include <memory>
#include <type_traits>

#include <OSMutex.h>
#include <OSGuard.h>

#include <device/CameraData.h>
#include <device/Camera.h>
#include <device/OprosPrintMessage.h>

#include "CameraServiceProvided.h"

class CameraComp: public Component
	,public ICameraService
{
public:
	struct DeviceHandleHelper
	{
		typedef std::remove_pointer<OprosDeviceHandle>::type Type;
		typedef std::unique_ptr<Type, DeviceHandleHelper> Pointer;
				
		static Pointer load(std::string const& path)
		{
#if defined(_WIN32)
			return Pointer(::LoadLibraryA(path.c_str()));
#else
			return Pointer(::dlopen(path.c_str(), RTLD_LAZY));
#endif
		}

		void operator()(OprosDeviceHandle p)
		{
#if defined(_WIN32)
			::FreeLibrary(p);
#else
			::dlclose(p);
#endif
		}
	};

private:
	// method for provider
	ICameraService *ptrCameraService;

private:
	//data
	OutputDataPort< OPRoS::CameraData > imageData;

public:
	// service
	virtual ReturnType SetProperty(OPRoS::Property parameter);
	virtual OPRoS::Property GetProperty();
	virtual ReturnType GetError();
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual OPRoS::CameraData GetImage();

public:
	CameraComp();
	CameraComp(const std::string &compId);
	virtual ~CameraComp();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();

private:
	DeviceHandleHelper::Pointer mpOprosAPI;
	std::unique_ptr<Camera> mpCamera;
	ReturnType mLastError;
	
	OSMutex mPropertyMutex;
	OPRoS::Property mProperty;
};

#endif

