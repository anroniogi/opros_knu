

#ifndef _LaserScannerService_REQUIRED_PORT_H
#define _LaserScannerService_REQUIRED_PORT_H

#include <OPRoSTypes.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <ProvidedServicePort.h>
#include <RequiredServicePort.h>
#include <ProvidedMethod.h>
#include <RequiredMethod.h>
#include <device/ApiTypes.h>


#include "device/Property.h"
		



/*
 * 
 * LaserScannerService : public RequiredServicePort
 *
 */
class LaserScannerServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef RequiredMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef RequiredMethod<std::vector<OPRoS::Float64Array>> GetSensorValueFuncType;
	GetSensorValueFuncType *GetSensorValueFunc;

public:
	//
	// Constructor
	//
	LaserScannerServiceRequired()
	{
            SetPropertyFunc = NULL;
            GetPropertyFunc = NULL;
            GetErrorFunc = NULL;
            EnableFunc = NULL;
            DisableFunc = NULL;
            GetSensorValueFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	ReturnType SetProperty(OPRoS::Property parameter)
	{
            opros_assert(SetPropertyFunc != NULL);
	
            return (*SetPropertyFunc)(parameter);
		
	}

	OPRoS::Property GetProperty()
	{
            opros_assert(GetPropertyFunc != NULL);
	
            return (*GetPropertyFunc)();
		
	}

	ReturnType GetError()
	{
            opros_assert(GetErrorFunc != NULL);
	
            return (*GetErrorFunc)();
		
	}

	ReturnType Enable()
	{
            opros_assert(EnableFunc != NULL);
	
            return (*EnableFunc)();
		
	}

	ReturnType Disable()
	{
            opros_assert(DisableFunc != NULL);
	
            return (*DisableFunc)();
		
	}

	std::vector<OPRoS::Float64Array> GetSensorValue()
	{
            opros_assert(GetSensorValueFunc != NULL);
	
            return (*GetSensorValueFunc)();
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&LaserScannerServiceRequired::SetProperty,"SetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&LaserScannerServiceRequired::GetProperty,"GetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&LaserScannerServiceRequired::GetError,"GetError");
        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&LaserScannerServiceRequired::Enable,"Enable");
        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&LaserScannerServiceRequired::Disable,"Disable");
        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&LaserScannerServiceRequired::GetSensorValue,"GetSensorValue");
        opros_assert(ptr_method != NULL);
        addMethod("GetSensorValue",ptr_method);
        GetSensorValueFunc = reinterpret_cast<GetSensorValueFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
