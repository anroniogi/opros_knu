

#ifndef _GlobalMapService_PROVIDED_PORT_H
#define _GlobalMapService_PROVIDED_PORT_H

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



#ifndef _IGlobalMapService_CLASS_DEF
#define _IGlobalMapService_CLASS_DEF
/*
 * IGlobalMapService
 *
 *  The comonent inherits this class and implements methods. 
 */
class IGlobalMapService
{
 public:
    virtual double GetMapCellSize()=0;
    virtual double GetMapStartX()=0;
    virtual double GetMapStartY()=0;
    virtual double GetMapWidth()=0;
    virtual double GetMapHeight()=0;
    virtual std::vector< std::vector< bool > > GetBinaryMap()=0;
 };
#endif

/*
 * 
 * GlobalMapService : public ProvidedServicePort
 *
 */
class GlobalMapServiceProvided
	:public ProvidedServicePort, public IGlobalMapService
{
protected:
    IGlobalMapService *pcom;


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

   typedef ProvidedMethod<std::vector< std::vector< bool > >> GetBinaryMapFuncType;
   GetBinaryMapFuncType *GetBinaryMapFunc;


public: // default method
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
   virtual std::vector< std::vector< bool > > GetBinaryMap()
   {
		opros_assert(GetBinaryMapFunc != NULL);
		
            return (*GetBinaryMapFunc)();
		
   }


public:
    //
    // Constructor
    //
    GlobalMapServiceProvided(IGlobalMapService *fn)
    {
        pcom = fn;

        GetMapCellSizeFunc = NULL;
        GetMapStartXFunc = NULL;
        GetMapStartYFunc = NULL;
        GetMapWidthFunc = NULL;
        GetMapHeightFunc = NULL;
        GetBinaryMapFunc = NULL;
        

        setup();
    }

    // generated setup function
    virtual void setup()
    {
        Method *ptr_method;
    
        ptr_method = makeProvidedMethod(&IGlobalMapService::GetMapCellSize,pcom,"GetMapCellSize");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapCellSize",ptr_method);
        GetMapCellSizeFunc = reinterpret_cast<GetMapCellSizeFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGlobalMapService::GetMapStartX,pcom,"GetMapStartX");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartX",ptr_method);
        GetMapStartXFunc = reinterpret_cast<GetMapStartXFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGlobalMapService::GetMapStartY,pcom,"GetMapStartY");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapStartY",ptr_method);
        GetMapStartYFunc = reinterpret_cast<GetMapStartYFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGlobalMapService::GetMapWidth,pcom,"GetMapWidth");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapWidth",ptr_method);
        GetMapWidthFunc = reinterpret_cast<GetMapWidthFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGlobalMapService::GetMapHeight,pcom,"GetMapHeight");

        opros_assert(ptr_method != NULL);
        addMethod("GetMapHeight",ptr_method);
        GetMapHeightFunc = reinterpret_cast<GetMapHeightFuncType *>(ptr_method);
        ptr_method = NULL;

    
        ptr_method = makeProvidedMethod(&IGlobalMapService::GetBinaryMap,pcom,"GetBinaryMap");

        opros_assert(ptr_method != NULL);
        addMethod("GetBinaryMap",ptr_method);
        GetBinaryMapFunc = reinterpret_cast<GetBinaryMapFuncType *>(ptr_method);
        ptr_method = NULL;

    
    }
};
#endif
