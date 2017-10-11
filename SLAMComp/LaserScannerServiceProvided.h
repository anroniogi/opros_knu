

#ifndef _LaserScannerService_PROVIDED_PORT_H
#define _LaserScannerService_PROVIDED_PORT_H

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
		

#ifndef _ILaserScannerService_CLASS_DEF
#define _ILaserScannerService_CLASS_DEF
/*
 * ILaserScannerService
 *
 *  The comonent inherits this class and implements methods. 
 */
class ILaserScannerService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
    virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
    virtual ReturnType Enable()=0;
    virtual ReturnType Disable()=0;
    virtual std::vector<OPRoS::Float64Array> GetSensorValue()=0;
 };
#endif

/*
 * 
 * LaserScannerService : public ProvidedServicePort
 *
 */
class LaserScannerServiceProvided
	:public ProvidedServicePort, public ILaserScannerService
{
protected:
    ILaserScannerService *pcom;


   typedef ProvidedMethod<ReturnType> SetPropertyFuncType;
   SetPropertyFuncType *SetPropertyFunc;

   typedef ProvidedMethod<OPRoS::Property> GetPropertyFuncType;
   GetPropertyFuncType *GetPropertyFunc;

   typedef ProvidedMethod<ReturnType> GetErrorFuncType;
   GetErrorFuncType *GetErrorFunc;

   typedef ProvidedMethod<ReturnType> EnableFuncType;
   EnableFuncType *EnableFunc;

   typedef ProvidedMethod<ReturnType> DisableFuncType;
   DisableFuncType *DisableFunc;

   typedef ProvidedMethod<std::vector<OPRoS::Float64Array>> GetSensorValueFuncType;
   GetSensorValueFuncType *GetSensorValueFunc;


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
   virtual ReturnType Enable()
   {
		opros_assert(EnableFunc != NULL);
		
            return (*EnableFunc)();
		
   }
   virtual ReturnType Disable()
   {
		opros_assert(DisableFunc != NULL);
		
            return (*DisableFunc)();
		
   }
   virtual std::vector<OPRoS::Float64Array> GetSensorValue()
   {
		opros_assert(GetSensorValueFunc != NULL);
		
            return (*GetSensorValueFunc)();
		
   }


public:
    //
    // Constructor
    //
    LaserScannerServiceProvided(ILaserScannerService *fn)
    {
        pcom = fn;

        SetPropertyFunc = NULL;
        GetPropertyFunc = NULL;
        GetErrorFunc = NULL;
        EnableFunc = NULL;
        DisableFunc = NULL;
        GetSensorValueFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&ILaserScannerService::SetProperty,pcom,"SetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ILaserScannerService::GetProperty,pcom,"GetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ILaserScannerService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ILaserScannerService::Enable,pcom,"Enable");

        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ILaserScannerService::Disable,pcom,"Disable");

        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ILaserScannerService::GetSensorValue,pcom,"GetSensorValue");

        opros_assert(ptr_method != NULL);
        addMethod("GetSensorValue",ptr_method);
        GetSensorValueFunc = reinterpret_cast<GetSensorValueFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
