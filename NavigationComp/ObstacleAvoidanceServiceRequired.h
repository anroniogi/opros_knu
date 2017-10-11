

#ifndef _ObstacleAvoidanceService_REQUIRED_PORT_H
#define _ObstacleAvoidanceService_REQUIRED_PORT_H

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

#include <device/Property.h>
#include <device/MobilePositionData.h>


/*
 * 
 * ObstacleAvoidanceService : public RequiredServicePort
 *
 */
class ObstacleAvoidanceServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<ReturnType> SetPositionFuncType;
	SetPositionFuncType *SetPositionFunc;

	typedef RequiredMethod<OPRoS::MobileVelocityData> AvoidFuncType;
	AvoidFuncType *AvoidFunc;

public:
	//
	// Constructor
	//
	ObstacleAvoidanceServiceRequired()
	{
            SetPropertyFunc = NULL;
            GetPropertyFunc = NULL;
            GetErrorFunc = NULL;
            SetPositionFunc = NULL;
            AvoidFunc = NULL;
            
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

	ReturnType SetPosition(OPRoS::MobilePositionData position)
	{
            opros_assert(SetPositionFunc != NULL);
	
            return (*SetPositionFunc)(position);
		
	}

	OPRoS::MobileVelocityData Avoid(OPRoS::MobilePositionData currentPosition,OPRoS::MobilePositionData targetPosition)
	{
            opros_assert(AvoidFunc != NULL);
	
            return (*AvoidFunc)(currentPosition,targetPosition);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&ObstacleAvoidanceServiceRequired::SetProperty,"SetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&ObstacleAvoidanceServiceRequired::GetProperty,"GetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&ObstacleAvoidanceServiceRequired::GetError,"GetError");
        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&ObstacleAvoidanceServiceRequired::SetPosition,"SetPosition");
        opros_assert(ptr_method != NULL);
        addMethod("SetPosition",ptr_method);
        SetPositionFunc = reinterpret_cast<SetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&ObstacleAvoidanceServiceRequired::Avoid,"Avoid");
        opros_assert(ptr_method != NULL);
        addMethod("Avoid",ptr_method);
        AvoidFunc = reinterpret_cast<AvoidFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
