

#ifndef _SLAMService_REQUIRED_PORT_H
#define _SLAMService_REQUIRED_PORT_H

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
		
#include <string>
		
#include <string>
		



/*
 * 
 * SLAMService : public RequiredServicePort
 *
 */
class SLAMServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<bool> LoadMapFileFuncType;
	LoadMapFileFuncType *LoadMapFileFunc;

	typedef RequiredMethod<bool> SaveMapFileFuncType;
	SaveMapFileFuncType *SaveMapFileFunc;

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

	typedef RequiredMethod<double> GetCellOccProbFuncType;
	GetCellOccProbFuncType *GetCellOccProbFunc;

	typedef RequiredMethod<bool> IsInFuncType;
	IsInFuncType *IsInFunc;

	typedef RequiredMethod<void> ReStartSLAMFuncType;
	ReStartSLAMFuncType *ReStartSLAMFunc;

	typedef RequiredMethod<OPRoS::MobilePositionData> GetPositionFuncType;
	GetPositionFuncType *GetPositionFunc;

	typedef RequiredMethod<std::vector< std::vector< double > >> GetMapFuncType;
	GetMapFuncType *GetMapFunc;

public:
	//
	// Constructor
	//
	SLAMServiceRequired()
	{
            SetPropertyFunc = NULL;
            GetPropertyFunc = NULL;
            GetErrorFunc = NULL;
            LoadMapFileFunc = NULL;
            SaveMapFileFunc = NULL;
            GetMapCellSizeFunc = NULL;
            GetMapStartXFunc = NULL;
            GetMapStartYFunc = NULL;
            GetMapWidthFunc = NULL;
            GetMapHeightFunc = NULL;
            GetCellOccProbFunc = NULL;
            IsInFunc = NULL;
            ReStartSLAMFunc = NULL;
            GetPositionFunc = NULL;
            GetMapFunc = NULL;
            
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

	bool LoadMapFile(std::string fileName)
	{
            opros_assert(LoadMapFileFunc != NULL);
	
            return (*LoadMapFileFunc)(fileName);
		
	}

	bool SaveMapFile(std::string fileName)
	{
            opros_assert(SaveMapFileFunc != NULL);
	
            return (*SaveMapFileFunc)(fileName);
		
	}

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

	double GetCellOccProb(double x,double y)
	{
            opros_assert(GetCellOccProbFunc != NULL);
	
            return (*GetCellOccProbFunc)(x,y);
		
	}

	bool IsIn(double x,double y)
	{
            opros_assert(IsInFunc != NULL);
	
            return (*IsInFunc)(x,y);
		
	}

	void ReStartSLAM()
	{
            opros_assert(ReStartSLAMFunc != NULL);
	
            (*ReStartSLAMFunc)();
		
	}

	OPRoS::MobilePositionData GetPosition()
	{
            opros_assert(GetPositionFunc != NULL);
	
            return (*GetPositionFunc)();
		
	}

	std::vector< std::vector< double > > GetMap()
	{
            opros_assert(GetMapFunc != NULL);
	
            return (*GetMapFunc)();
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::SetProperty,"SetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetProperty,"GetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetError,"GetError");
        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::LoadMapFile,"LoadMapFile");
        opros_assert(ptr_method != NULL);
        addMethod("LoadMapFile",ptr_method);
        LoadMapFileFunc = reinterpret_cast<LoadMapFileFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::SaveMapFile,"SaveMapFile");
        opros_assert(ptr_method != NULL);
        addMethod("SaveMapFile",ptr_method);
        SaveMapFileFunc = reinterpret_cast<SaveMapFileFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetMapCellSize,"GetMapCellSize");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapCellSize",ptr_method);
        GetMapCellSizeFunc = reinterpret_cast<GetMapCellSizeFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetMapStartX,"GetMapStartX");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartX",ptr_method);
        GetMapStartXFunc = reinterpret_cast<GetMapStartXFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetMapStartY,"GetMapStartY");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartY",ptr_method);
        GetMapStartYFunc = reinterpret_cast<GetMapStartYFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetMapWidth,"GetMapWidth");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapWidth",ptr_method);
        GetMapWidthFunc = reinterpret_cast<GetMapWidthFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetMapHeight,"GetMapHeight");
        opros_assert(ptr_method != NULL);
        addMethod("GetMapHeight",ptr_method);
        GetMapHeightFunc = reinterpret_cast<GetMapHeightFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetCellOccProb,"GetCellOccProb");
        opros_assert(ptr_method != NULL);
        addMethod("GetCellOccProb",ptr_method);
        GetCellOccProbFunc = reinterpret_cast<GetCellOccProbFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::IsIn,"IsIn");
        opros_assert(ptr_method != NULL);
        addMethod("IsIn",ptr_method);
        IsInFunc = reinterpret_cast<IsInFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::ReStartSLAM,"ReStartSLAM");
        opros_assert(ptr_method != NULL);
        addMethod("ReStartSLAM",ptr_method);
        ReStartSLAMFunc = reinterpret_cast<ReStartSLAMFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetPosition,"GetPosition");
        opros_assert(ptr_method != NULL);
        addMethod("GetPosition",ptr_method);
        GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&SLAMServiceRequired::GetMap,"GetMap");
        opros_assert(ptr_method != NULL);
        addMethod("GetMap",ptr_method);
        GetMapFunc = reinterpret_cast<GetMapFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
