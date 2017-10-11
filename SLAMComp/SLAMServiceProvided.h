

#ifndef _SLAMService_PROVIDED_PORT_H
#define _SLAMService_PROVIDED_PORT_H

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
		
#include <string>
		
#include <string>
		

#ifndef _ISLAMService_CLASS_DEF
#define _ISLAMService_CLASS_DEF
/*
 * ISLAMService
 *
 *  The comonent inherits this class and implements methods. 
 */
class ISLAMService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
    virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
    virtual bool LoadMapFile(std::string fileName)=0;
    virtual bool SaveMapFile(std::string fileName)=0;
    virtual double GetMapCellSize()=0;
    virtual double GetMapStartX()=0;
    virtual double GetMapStartY()=0;
    virtual double GetMapWidth()=0;
    virtual double GetMapHeight()=0;
    virtual double GetCellOccProb(double x,double y)=0;
    virtual bool IsIn(double x,double y)=0;
    virtual void ReStartSLAM()=0;
    virtual OPRoS::MobilePositionData GetPosition()=0;
    virtual std::vector< std::vector< double > > GetMap()=0;
 };
#endif

/*
 * 
 * SLAMService : public ProvidedServicePort
 *
 */
class SLAMServiceProvided
	:public ProvidedServicePort, public ISLAMService
{
protected:
    ISLAMService *pcom;


   typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
   SetPropertyFuncType *SetPropertyFunc;

   typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
   GetPropertyFuncType *GetPropertyFunc;

   typedef ProvidedMethod<ReturnType> GetErrorFuncType;
   GetErrorFuncType *GetErrorFunc;

   typedef ProvidedMethod<bool> LoadMapFileFuncType;
   LoadMapFileFuncType *LoadMapFileFunc;

   typedef ProvidedMethod<bool> SaveMapFileFuncType;
   SaveMapFileFuncType *SaveMapFileFunc;

   typedef ProvidedMethod<double> GetMapCellSizeFuncType;
   GetMapCellSizeFuncType *GetMapCellSizeFunc;

   typedef ProvidedMethod<double> GetMapStartXFuncType;
   GetMapStartXFuncType *GetMapStartXFunc;

   typedef ProvidedMethod<double> GetMapStartYFuncType;
   GetMapStartYFuncType *GetMapStartYFunc;

   typedef ProvidedMethod<double> GetMapWidthFuncType;
   GetMapWidthFuncType *GetMapWidthFunc;

   typedef ProvidedMethod<double> GetMapHeightFuncType;
   GetMapHeightFuncType *GetMapHeightFunc;

   typedef ProvidedMethod<double> GetCellOccProbFuncType;
   GetCellOccProbFuncType *GetCellOccProbFunc;

   typedef ProvidedMethod<bool> IsInFuncType;
   IsInFuncType *IsInFunc;

   typedef ProvidedMethod<void> ReStartSLAMFuncType;
   ReStartSLAMFuncType *ReStartSLAMFunc;

   typedef ProvidedMethod<OPRoS::MobilePositionData> GetPositionFuncType;
   GetPositionFuncType *GetPositionFunc;

   typedef ProvidedMethod<std::vector< std::vector< double > >> GetMapFuncType;
   GetMapFuncType *GetMapFunc;


public: // default method
   virtual ReturnType SetProperty(OPRoS::Property parameter)
   {
		opros_assert(SetPropertyFunc != NULL);
		
            return (*SetPropertyFunc)(parameter);
		
   }
   virtual OPRoS::Property GetProperty()
   {
		opros_assert(GetPropertyFunc != NULL);
		
            return (*GetPropertyFunc)();
		
   }
   virtual ReturnType GetError()
   {
		opros_assert(GetErrorFunc != NULL);
		
            return (*GetErrorFunc)();
		
   }
   virtual bool LoadMapFile(std::string fileName)
   {
		opros_assert(LoadMapFileFunc != NULL);
		
            return (*LoadMapFileFunc)(fileName);
		
   }
   virtual bool SaveMapFile(std::string fileName)
   {
		opros_assert(SaveMapFileFunc != NULL);
		
            return (*SaveMapFileFunc)(fileName);
		
   }
   virtual double GetMapCellSize()
   {
		opros_assert(GetMapCellSizeFunc != NULL);
		
            return (*GetMapCellSizeFunc)();
		
   }
   virtual double GetMapStartX()
   {
		opros_assert(GetMapStartXFunc != NULL);
		
            return (*GetMapStartXFunc)();
		
   }
   virtual double GetMapStartY()
   {
		opros_assert(GetMapStartYFunc != NULL);
		
            return (*GetMapStartYFunc)();
		
   }
   virtual double GetMapWidth()
   {
		opros_assert(GetMapWidthFunc != NULL);
		
            return (*GetMapWidthFunc)();
		
   }
   virtual double GetMapHeight()
   {
		opros_assert(GetMapHeightFunc != NULL);
		
            return (*GetMapHeightFunc)();
		
   }
   virtual double GetCellOccProb(double x,double y)
   {
		opros_assert(GetCellOccProbFunc != NULL);
		
            return (*GetCellOccProbFunc)(x,y);
		
   }
   virtual bool IsIn(double x,double y)
   {
		opros_assert(IsInFunc != NULL);
		
            return (*IsInFunc)(x,y);
		
   }
   virtual void ReStartSLAM()
   {
		opros_assert(ReStartSLAMFunc != NULL);
		(*ReStartSLAMFunc)();
   }
   virtual OPRoS::MobilePositionData GetPosition()
   {
		opros_assert(GetPositionFunc != NULL);
		
            return (*GetPositionFunc)();
		
   }
   virtual std::vector< std::vector< double > > GetMap()
   {
		opros_assert(GetMapFunc != NULL);
		
            return (*GetMapFunc)();
		
   }


public:
    //
    // Constructor
    //
    SLAMServiceProvided(ISLAMService *fn)
    {
        pcom = fn;

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

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&ISLAMService::SetProperty,pcom,"SetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetProperty,pcom,"GetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::LoadMapFile,pcom,"LoadMapFile");

        opros_assert(ptr_method != NULL);
        addMethod("LoadMapFile",ptr_method);
        LoadMapFileFunc = reinterpret_cast<LoadMapFileFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::SaveMapFile,pcom,"SaveMapFile");

        opros_assert(ptr_method != NULL);
        addMethod("SaveMapFile",ptr_method);
        SaveMapFileFunc = reinterpret_cast<SaveMapFileFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetMapCellSize,pcom,"GetMapCellSize");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapCellSize",ptr_method);
        GetMapCellSizeFunc = reinterpret_cast<GetMapCellSizeFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetMapStartX,pcom,"GetMapStartX");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartX",ptr_method);
        GetMapStartXFunc = reinterpret_cast<GetMapStartXFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetMapStartY,pcom,"GetMapStartY");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartY",ptr_method);
        GetMapStartYFunc = reinterpret_cast<GetMapStartYFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetMapWidth,pcom,"GetMapWidth");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapWidth",ptr_method);
        GetMapWidthFunc = reinterpret_cast<GetMapWidthFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetMapHeight,pcom,"GetMapHeight");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapHeight",ptr_method);
        GetMapHeightFunc = reinterpret_cast<GetMapHeightFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetCellOccProb,pcom,"GetCellOccProb");

        opros_assert(ptr_method != NULL);
        addMethod("GetCellOccProb",ptr_method);
        GetCellOccProbFunc = reinterpret_cast<GetCellOccProbFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::IsIn,pcom,"IsIn");

        opros_assert(ptr_method != NULL);
        addMethod("IsIn",ptr_method);
        IsInFunc = reinterpret_cast<IsInFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::ReStartSLAM,pcom,"ReStartSLAM");

        opros_assert(ptr_method != NULL);
        addMethod("ReStartSLAM",ptr_method);
        ReStartSLAMFunc = reinterpret_cast<ReStartSLAMFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetPosition,pcom,"GetPosition");

        opros_assert(ptr_method != NULL);
        addMethod("GetPosition",ptr_method);
        GetPositionFunc = reinterpret_cast<GetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ISLAMService::GetMap,pcom,"GetMap");

        opros_assert(ptr_method != NULL);
        addMethod("GetMap",ptr_method);
        GetMapFunc = reinterpret_cast<GetMapFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
