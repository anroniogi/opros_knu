

#ifndef _ObstacleAvoidanceService_PROVIDED_PORT_H
#define _ObstacleAvoidanceService_PROVIDED_PORT_H

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
		

#ifndef _IObstacleAvoidanceService_CLASS_DEF
#define _IObstacleAvoidanceService_CLASS_DEF
/*
 * IObstacleAvoidanceService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IObstacleAvoidanceService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
    virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
    virtual ReturnType SetPosition(OPRoS::MobilePositionData position)=0;
    virtual OPRoS::MobileVelocityData Avoid(OPRoS::MobilePositionData currentPosition,OPRoS::MobilePositionData targetPosition)=0;
 };
#endif

/*
 * 
 * ObstacleAvoidanceService : public ProvidedServicePort
 *
 */
class ObstacleAvoidanceServiceProvided
	:public ProvidedServicePort, public IObstacleAvoidanceService
{
protected:
    IObstacleAvoidanceService *pcom;


   typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
   SetPropertyFuncType *SetPropertyFunc;

   typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
   GetPropertyFuncType *GetPropertyFunc;

   typedef ProvidedMethod<ReturnType> GetErrorFuncType;
   GetErrorFuncType *GetErrorFunc;

   typedef ProvidedMethod<ReturnType> SetPositionFuncType;
   SetPositionFuncType *SetPositionFunc;

   typedef ProvidedMethod<OPRoS::MobileVelocityData> AvoidFuncType;
   AvoidFuncType *AvoidFunc;


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
   virtual ReturnType SetPosition(OPRoS::MobilePositionData position)
   {
		opros_assert(SetPositionFunc != NULL);
		
            return (*SetPositionFunc)(position);
		
   }
   virtual OPRoS::MobileVelocityData Avoid(OPRoS::MobilePositionData currentPosition,OPRoS::MobilePositionData targetPosition)
   {
		opros_assert(AvoidFunc != NULL);
		
            return (*AvoidFunc)(currentPosition,targetPosition);
		
   }


public:
    //
    // Constructor
    //
    ObstacleAvoidanceServiceProvided(IObstacleAvoidanceService *fn)
    {
        pcom = fn;

        SetPropertyFunc = NULL;
        GetPropertyFunc = NULL;
        GetErrorFunc = NULL;
        SetPositionFunc = NULL;
        AvoidFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IObstacleAvoidanceService::SetProperty,pcom,"SetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IObstacleAvoidanceService::GetProperty,pcom,"GetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IObstacleAvoidanceService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IObstacleAvoidanceService::SetPosition,pcom,"SetPosition");

        opros_assert(ptr_method != NULL);
        addMethod("SetPosition",ptr_method);
        SetPositionFunc = reinterpret_cast<SetPositionFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IObstacleAvoidanceService::Avoid,pcom,"Avoid");

        opros_assert(ptr_method != NULL);
        addMethod("Avoid",ptr_method);
        AvoidFunc = reinterpret_cast<AvoidFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
