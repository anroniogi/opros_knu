

#ifndef _VisionRecognitionService_PROVIDED_PORT_H
#define _VisionRecognitionService_PROVIDED_PORT_H

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
#include "device/VisionRecognitionResultData.h"
		

#ifndef _IVisionRecognitionService_CLASS_DEF
#define _IVisionRecognitionService_CLASS_DEF
/*
 * IVisionRecognitionService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IVisionRecognitionService
{
 public:
    virtual ReturnType SetProperty(OPRoS::Property parameter)=0;
    virtual OPRoS::Property GetProperty()=0;
    virtual ReturnType GetError()=0;
    virtual ReturnType Enable()=0;
    virtual ReturnType Disable()=0;

	virtual std::vector<OPRoS::VisionRecognitionResultData> Recognize(vector<unsigned char> image,int width,int height,int pixelBytesstd::)=0;
 };
#endif

/*
 * 
 * VisionRecognitionService : public ProvidedServicePort
 *
 */
class VisionRecognitionServiceProvided
	:public ProvidedServicePort, public IVisionRecognitionService
{
protected:
    IVisionRecognitionService *pcom;


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

   typedef ProvidedMethod<std::vector<OPRoS::VisionRecognitionResultData>> RecognizeFuncType;
   RecognizeFuncType *RecognizeFunc;


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
   virtual std::vector<OPRoS::VisionRecognitionResultData> Recognize(vector<unsigned char> image,int width,int height,int pixelBytesstd::)
   {
		opros_assert(RecognizeFunc != NULL);
		
            return (*RecognizeFunc)(image,width,height,pixelBytes);
		
   }


public:
    //
    // Constructor
    //
    VisionRecognitionServiceProvided(IVisionRecognitionService *fn)
    {
        pcom = fn;

        SetPropertyFunc = NULL;
        GetPropertyFunc = NULL;
        GetErrorFunc = NULL;
        EnableFunc = NULL;
        DisableFunc = NULL;
        RecognizeFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IVisionRecognitionService::SetProperty,pcom,"SetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IVisionRecognitionService::GetProperty,pcom,"GetProperty");

        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IVisionRecognitionService::GetError,pcom,"GetError");

        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IVisionRecognitionService::Enable,pcom,"Enable");

        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IVisionRecognitionService::Disable,pcom,"Disable");

        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IVisionRecognitionService::Recognize,pcom,"Recognize");

        opros_assert(ptr_method != NULL);
        addMethod("Recognize",ptr_method);
        RecognizeFunc = reinterpret_cast<RecognizeFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
