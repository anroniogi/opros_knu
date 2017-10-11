

#ifndef _GlobalMapService_REQUIRED_PORT_H
#define _GlobalMapService_REQUIRED_PORT_H

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





/*
 * 
 * GlobalMapService : public RequiredServicePort
 *
 */
class GlobalMapServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<double> GetMapCellSizeFuncType;
	GetMapCellSizeFuncType *GetMapCellSizeFunc;

	typedef RequiredMethod<double> GetMapStartXFuncType;
	GetMapStartXFuncType *GetMapStartXFunc;

	typedef RequiredMethod<double> GetMapStartYFuncType;
	GetMapStartYFuncType *GetMapStartYFunc;

	typedef RequiredMethod<double> GetMapWidthFuncType;
	GetMapWidthFuncType *GetMapWidthFunc;

	typedef RequiredMethod<double> GetMapHeightFuncType;
	GetMapHeightFuncType *GetMapHeightFunc;

	typedef RequiredMethod<std::vector< std::vector< bool > >> GetBinaryMapFuncType;
	GetBinaryMapFuncType *GetBinaryMapFunc;

public:
	//
	// Constructor
	//
	GlobalMapServiceRequired()
	{
            GetMapCellSizeFunc = NULL;
            GetMapStartXFunc = NULL;
            GetMapStartYFunc = NULL;
            GetMapWidthFunc = NULL;
            GetMapHeightFunc = NULL;
            GetBinaryMapFunc = NULL;
            
	   setup();
	}

	// method implementation for required method
	double GetMapCellSize()
	{
            opros_assert(GetMapCellSizeFunc != NULL);
	
            return (*GetMapCellSizeFunc)();
		
	}

	double GetMapStartX()
	{
            opros_assert(GetMapStartXFunc != NULL);
	
            return (*GetMapStartXFunc)();
		
	}

	double GetMapStartY()
	{
            opros_assert(GetMapStartYFunc != NULL);
	
            return (*GetMapStartYFunc)();
		
	}

	double GetMapWidth()
	{
            opros_assert(GetMapWidthFunc != NULL);
	
            return (*GetMapWidthFunc)();
		
	}

	double GetMapHeight()
	{
            opros_assert(GetMapHeightFunc != NULL);
	
            return (*GetMapHeightFunc)();
		
	}

	std::vector< std::vector< bool > > GetBinaryMap()
	{
            opros_assert(GetBinaryMapFunc != NULL);
	
            return (*GetBinaryMapFunc)();
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&GlobalMapServiceRequired::GetMapCellSize,"GetMapCellSize");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapCellSize",ptr_method);
        GetMapCellSizeFunc = reinterpret_cast<GetMapCellSizeFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GlobalMapServiceRequired::GetMapStartX,"GetMapStartX");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartX",ptr_method);
        GetMapStartXFunc = reinterpret_cast<GetMapStartXFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GlobalMapServiceRequired::GetMapStartY,"GetMapStartY");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartY",ptr_method);
        GetMapStartYFunc = reinterpret_cast<GetMapStartYFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GlobalMapServiceRequired::GetMapWidth,"GetMapWidth");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapWidth",ptr_method);
        GetMapWidthFunc = reinterpret_cast<GetMapWidthFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GlobalMapServiceRequired::GetMapHeight,"GetMapHeight");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapHeight",ptr_method);
        GetMapHeightFunc = reinterpret_cast<GetMapHeightFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&GlobalMapServiceRequired::GetBinaryMap,"GetBinaryMap");
        opros_assert(ptr_method != NULL);
        addMethod("GetBinaryMap",ptr_method);
        GetBinaryMapFunc = reinterpret_cast<GetBinaryMapFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
