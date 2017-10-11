

#ifndef _CameraService_PROVIDED_PORT_H
#define _CameraService_PROVIDED_PORT_H

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
		

#ifndef _ICameraService_CLASS_DEF
#define _ICameraService_CLASS_DEF
/*
 * ICameraService
 *
 *  The comonent inherits this class and implements methods. 
 */
class ICameraService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
    virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
    virtual ReturnType Enable()=0;
    virtual ReturnType Disable()=0;
    virtual OPRoS::CameraData GetImage()=0;
 };
#endif

/*
 * 
 * CameraService : public ProvidedServicePort
 *
 */
class CameraServiceProvided
	:public ProvidedServicePort, public ICameraService
{
protected:
    ICameraService *pcom;


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

   typedef ProvidedMethod<OPRoS::CameraData> GetImageFuncType;
   GetImageFuncType *GetImageFunc;


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
   virtual OPRoS::CameraData GetImage()
   {
		opros_assert(GetImageFunc != NULL);
		
            return (*GetImageFunc)();
		
   }


public:
    //
    // Constructor
    //
    CameraServiceProvided(ICameraService *fn)
    {
        pcom = fn;

        SetPropertyFunc = NULL;
        GetPropertyFunc = NULL;
        GetErrorFunc = NULL;
        EnableFunc = NULL;
        DisableFunc = NULL;
        GetImageFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&ICameraService::SetProperty,pcom,"SetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ICameraService::GetProperty,pcom,"GetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ICameraService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ICameraService::Enable,pcom,"Enable");

        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ICameraService::Disable,pcom,"Disable");

        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&ICameraService::GetImage,pcom,"GetImage");

        opros_assert(ptr_method != NULL);
        addMethod("GetImage",ptr_method);
        GetImageFunc = reinterpret_cast<GetImageFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
