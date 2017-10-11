

#ifndef _PathPlanningService_REQUIRED_PORT_H
#define _PathPlanningService_REQUIRED_PORT_H

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


#include "OPRoS::Property.h"
		
#include "OPRoS::MobilePositionData.h"
		



/*
 * 
 * PathPlanningService : public RequiredServicePort
 *
 */
class PathPlanningServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<vector<OPRoS::MobilePositionData>> FindPathFuncType;
	FindPathFuncType *FindPathFunc;

public:
	//
	// Constructor
	//
	PathPlanningServiceRequired()
	{
            SetPropertyFunc = NULL;
            GetPropertyFunc = NULL;
            GetErrorFunc = NULL;
            FindPathFunc = NULL;
            
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

	vector<OPRoS::MobilePositionData> FindPath(OPRoS::MobilePositionData startPosition,OPRoS::MobilePositionData endPosition)
	{
            opros_assert(FindPathFunc != NULL);
	
            return (*FindPathFunc)(startPosition,endPosition);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&PathPlanningServiceRequired::SetProperty,"SetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&PathPlanningServiceRequired::GetProperty,"GetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&PathPlanningServiceRequired::GetError,"GetError");
        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&PathPlanningServiceRequired::FindPath,"FindPath");
        opros_assert(ptr_method != NULL);
        addMethod("FindPath",ptr_method);
        FindPathFunc = reinterpret_cast<FindPathFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
