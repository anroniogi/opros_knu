

#ifndef _PathPlanningService_PROVIDED_PORT_H
#define _PathPlanningService_PROVIDED_PORT_H

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
		

#ifndef _IPathPlanningService_CLASS_DEF
#define _IPathPlanningService_CLASS_DEF
/*
 * IPathPlanningService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IPathPlanningService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
    virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
    virtual vector<OPRoS::MobilePositionData> FindPath(OPRoS::MobilePositionData startPosition,OPRoS::MobilePositionData endPosition)=0;
 };
#endif

/*
 * 
 * PathPlanningService : public ProvidedServicePort
 *
 */
class PathPlanningServiceProvided
	:public ProvidedServicePort, public IPathPlanningService
{
protected:
    IPathPlanningService *pcom;


   typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
   SetPropertyFuncType *SetPropertyFunc;

   typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
   GetPropertyFuncType *GetPropertyFunc;

   typedef ProvidedMethod<ReturnType> GetErrorFuncType;
   GetErrorFuncType *GetErrorFunc;

   typedef ProvidedMethod<vector<OPRoS::MobilePositionData>> FindPathFuncType;
   FindPathFuncType *FindPathFunc;


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
   virtual vector<OPRoS::MobilePositionData> FindPath(OPRoS::MobilePositionData startPosition,OPRoS::MobilePositionData endPosition)
   {
		opros_assert(FindPathFunc != NULL);
		
            return (*FindPathFunc)(startPosition,endPosition);
		
   }


public:
    //
    // Constructor
    //
    PathPlanningServiceProvided(IPathPlanningService *fn)
    {
        pcom = fn;

        SetPropertyFunc = NULL;
        GetPropertyFunc = NULL;
        GetErrorFunc = NULL;
        FindPathFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IPathPlanningService::SetProperty,pcom,"SetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IPathPlanningService::GetProperty,pcom,"GetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IPathPlanningService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IPathPlanningService::FindPath,pcom,"FindPath");

        opros_assert(ptr_method != NULL);
        addMethod("FindPath",ptr_method);
        FindPathFunc = reinterpret_cast<FindPathFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
