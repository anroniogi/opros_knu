
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "CameraComp.h"

#include <algorithm>

//
// constructor declaration
//
CameraComp::CameraComp()
	: mpOprosAPI(), mLastError(OPROS_SUCCESS), mpCamera()
{
	portSetup();
}

//
// constructor declaration (with name)
//
CameraComp::CameraComp(const std::string &name)
	: Component(name), mpOprosAPI(), mLastError(OPROS_SUCCESS), mpCamera()
{
	portSetup();
}

//
// destructor declaration
//

CameraComp::~CameraComp()
{
	mpCamera.reset();
	mpOprosAPI.reset();
}

OPRoS::CameraData CameraComp::GetImage()
{
	OPRoS::CameraData data;
	if (!mpCamera)
	{
		PrintMessage("ERROR : CameraComp::onExecute() -> Camera device is NULL.\n");
		data.status = mLastError = OPROS_PRECONDITION_NOT_MET;
		return data;
	}
	
	data.status = mLastError = mpCamera->GetImage(data);
	return data;
}

ReturnType CameraComp::Disable()
{
	if (!mpCamera)
	{
		PrintMessage("ERROR : CameraComp::Disable() -> Camera device is NULL.\n");
		return mLastError = OPROS_PRECONDITION_NOT_MET;
	}

	//	API의 disable를 호출
	if (mpCamera->Disable() != API_SUCCESS)
	{
		PrintMessage("ERROR : CameraComp::Disable() -> Can't disable the Camera API\n");
		return mLastError = OPROS_ENABLE_API_ERROR;
	}

	return mLastError = OPROS_SUCCESS;
}

ReturnType CameraComp::Enable()
{
	if (!mpCamera)
	{
		PrintMessage("ERROR : CameraComp::Enable() -> Camera device is NULL.\n");
		return mLastError = OPROS_PRECONDITION_NOT_MET;
	}

	//	API의 enable를 호출
	if (mpCamera->Enable() != API_SUCCESS)
	{
		PrintMessage("ERROR : CameraComp::Enable() -> Can't enable the Camera API\n");
		return mLastError = OPROS_ENABLE_API_ERROR;
	}
	return mLastError = OPROS_SUCCESS;
}

ReturnType CameraComp::GetError()
{
	return mLastError;
}

OPRoS::Property CameraComp::GetProperty()
{
	OSGuard guard(&mPropertyMutex);

	OPRoS::Property property;

	if (!mpCamera)
	{
		PrintMessage("ERROR : CameraComp::GetProperty() -> Camera device is NULL.\n");		
		property.status = mLastError = OPROS_PRECONDITION_NOT_MET;
		return property;
	}

	property = mProperty;
	property.status = mLastError = mpCamera->GetProperty(property);

	if (property.status != API_SUCCESS)
	{
		PrintMessage("ERROR : CameraComp::GetProperty() -> Can't get property from camera device \n");
		return property;
	}

	return property;
}

ReturnType CameraComp::SetProperty(OPRoS::Property property)
{
	OSGuard guard(&mPropertyMutex);

	LifecycleState const prevLifeState = Component::getStatus();

	if (prevLifeState == OPROS_CS_ACTIVE)
	{
		ReturnType status = Component::stop();
		if (status != OPROS_SUCCESS)
		{
			PrintMessage("ERROR : CameraComp::SetProperty() -> Can't stop component.\n");
			return mLastError = status;
		}
	}

	bool isNewDevice = false;
	if (!property.FindName("ApiName"))
	{
		if (!mpCamera)
		{
			PrintMessage("ERROR : CameraComp::SetProperty() -> Can't find the ApiName in property\n");
			return mLastError = OPROS_FIND_PROPERTY_ERROR;
		}
	}
	else
	{
		std::string path = property.GetValue("ApiName");
		if (path != mProperty.GetValue("ApiName"))
		{
			DeviceHandleHelper::Pointer pLibrary(DeviceHandleHelper::load(path));

			if (!pLibrary)
			{
				PrintMessage("ERROR : CameraComp::SetProperty() -> Can't find the %s\n", property.GetValue("ApiName").c_str());
				return mLastError = OPROS_FIND_DLL_ERROR;
			}

			//	API 로드
			GET_OPROS_DEVICE getOprosDevice = nullptr;
#if defined(_WIN32)
			getOprosDevice = reinterpret_cast<GET_OPROS_DEVICE>(::GetProcAddress(pLibrary.get(), "GetAPI"));
#else
			getOprosDevice = reinterpret_cast<GET_OPROS_DEVICE>(::dlsym(pLibrary.get(), "GetAPI"));
#endif

			if (!getOprosDevice)
			{
				PrintMessage("ERROR : CameraComp::SetProperty() -> Can't get a handle of GetAPI Funtion\n");
				return mLastError = OPROS_LOAD_DLL_ERROR;
			}

			std::unique_ptr<Camera> pCamera(static_cast<Camera*>(getOprosDevice()));
			if (!pCamera)
			{
				PrintMessage("ERROR : CameraComp::SetProperty() -> Can't get a handle of Camera API\n");
				return mLastError = OPROS_LOAD_DLL_ERROR;
			}

			//	API 초기화
			if (pCamera->Initialize(property) != API_SUCCESS)
			{
				PrintMessage("ERROR : CameraComp::SetProperty() -> Can't intilaize a Camera API\n");
				return mLastError = OPROS_INITIALIZE_API_ERROR;
			}

			mpOprosAPI.swap(pLibrary);
			mpCamera.swap(pCamera);
		
			isNewDevice = true;
		}
	}

	if (!isNewDevice)
	{
		if (mpCamera->SetProperty(property) != API_SUCCESS)
		{
			PrintMessage("ERROR : CameraComp::SetProperty() -> Can't set property to camera device \n");
			return mLastError = OPROS_CALL_API_ERROR;
		}
	}

	mProperty = property;

	if (prevLifeState == OPROS_CS_ACTIVE)
	{
		ReturnType status = Component::start();
		if (status != OPROS_SUCCESS)
		{
			PrintMessage("ERROR : CameraComp::SetProperty() -> Can't start component.\n");
			return mLastError = status;
		}
	}

	return mLastError = OPROS_SUCCESS;
}

void CameraComp::portSetup()
{
	//data port setup
	addPort("imageData", &imageData);

	ProvidedServicePort *pa1;
	pa1 = new CameraServiceProvided(this);
	addPort("CameraService", pa1);

	// export variable setup
}

// Call back Declaration
ReturnType CameraComp::onInitialize()
{
	OPRoS::Property property;
	property.SetProperty(getPropertyMap());
	return SetProperty(property);
}

ReturnType CameraComp::onStart()
{
	return Enable();
}
	
ReturnType CameraComp::onStop()
{
	return Disable();
}

ReturnType CameraComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CameraComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CameraComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CameraComp::onDestroy()
{
	mpCamera.reset();
	mpOprosAPI.reset();
	return OPROS_SUCCESS;
}

ReturnType CameraComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CameraComp::onExecute()
{
	OPRoS::CameraData data(GetImage());
	if (data.status == OPROS_SUCCESS)
		imageData.push(data);
	else
		PrintMessage("ERROR : CameraComp::onExecute() -> Can't get image from device.\n");

	return OPROS_SUCCESS;
}
	
ReturnType CameraComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CameraComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}

#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new CameraComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new CameraComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

