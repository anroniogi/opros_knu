

#ifndef _VisionRecognitionService_REQUIRED_PORT_H
#define _VisionRecognitionService_REQUIRED_PORT_H

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
		



/*
 * 
 * VisionRecognitionService : public RequiredServicePort
 *
 */
class VisionRecognitionServiceRequired
   :public RequiredServicePort
{
protected:

	typedef RequiredMethod<ReturnType> SetPropertyFuncType;
	SetPropertyFuncType *SetPropertyFunc;

	typedef RequiredMethod<OPRoS::Property> GetPropertyFuncType;
	GetPropertyFuncType *GetPropertyFunc;

	typedef RequiredMethod<ReturnType> GetErrorFuncType;
	GetErrorFuncType *GetErrorFunc;

	typedef RequiredMethod<ReturnType> EnableFuncType;
	EnableFuncType *EnableFunc;

	typedef RequiredMethod<ReturnType> DisableFuncType;
	DisableFuncType *DisableFunc;

	typedef RequiredMethod<std::vector<VisionRecognitionResultData>> RecognizeFuncType;
	RecognizeFuncType *RecognizeFunc;

public:
	//
	// Constructor
	//
	VisionRecognitionServiceRequired()
	{
            SetPropertyFunc = NULL;
            GetPropertyFunc = NULL;
            GetErrorFunc = NULL;
            EnableFunc = NULL;
            DisableFunc = NULL;
            RecognizeFunc = NULL;
            
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

	ReturnType Enable()
	{
            opros_assert(EnableFunc != NULL);
	
            return (*EnableFunc)();
		
	}

	ReturnType Disable()
	{
            opros_assert(DisableFunc != NULL);
	
            return (*DisableFunc)();
		
	}

	std::vector<VisionRecognitionResultData> Recognize(vector<unsigned char> image,int width,int height,int pixelBytes)
	{
            opros_assert(RecognizeFunc != NULL);
	
            return (*RecognizeFunc)(image,width,height,pixelBytes);
		
	}

	

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeRequiredMethod(&VisionRecognitionServiceRequired::SetProperty,"SetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("SetProperty",ptr_method);
        SetPropertyFunc = reinterpret_cast<SetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&VisionRecognitionServiceRequired::GetProperty,"GetProperty");
        opros_assert(ptr_method != NULL);
        addMethod("GetProperty",ptr_method);
        GetPropertyFunc = reinterpret_cast<GetPropertyFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&VisionRecognitionServiceRequired::GetError,"GetError");
        opros_assert(ptr_method != NULL);
        addMethod("GetError",ptr_method);
        GetErrorFunc = reinterpret_cast<GetErrorFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&VisionRecognitionServiceRequired::Enable,"Enable");
        opros_assert(ptr_method != NULL);
        addMethod("Enable",ptr_method);
        EnableFunc = reinterpret_cast<EnableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&VisionRecognitionServiceRequired::Disable,"Disable");
        opros_assert(ptr_method != NULL);
        addMethod("Disable",ptr_method);
        DisableFunc = reinterpret_cast<DisableFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeRequiredMethod(&VisionRecognitionServiceRequired::Recognize,"Recognize");
        opros_assert(ptr_method != NULL);
        addMethod("Recognize",ptr_method);
        RecognizeFunc = reinterpret_cast<RecognizeFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
