
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "MobilTestComp.h"

//
// constructor declaration
//
MobilTestComp::MobilTestComp()
{
	ptrMobileControllerService = NULL;


	
	portSetup();
}

//
// constructor declaration (with name)
//
MobilTestComp::MobilTestComp(const std::string &name):Component(name)
{
	ptrMobileControllerService = NULL;


	
	portSetup();
}

//
// destructor declaration
//

MobilTestComp::~MobilTestComp() {
}

void MobilTestComp::portSetup() {
	ptrMobileControllerService=new MobileControllerServiceRequired();
	addPort("MobileControllerService",ptrMobileControllerService);




	// export variable setup


}

// Call back Declaration
ReturnType MobilTestComp::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType MobilTestComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onExecute()
{
	// user code here
	OPRoS::MobileVelocityData value;
	value.x = 10;

	ptrMobileControllerService->SetVelocity(value);
	return OPROS_SUCCESS;
}
	
ReturnType MobilTestComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType MobilTestComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}







#ifndef MAKE_STATIC_COMPONENT
#ifdef WIN32

extern "C"
{
__declspec(dllexport) Component *getComponent();
__declspec(dllexport) void releaseComponent(Component *pcom);
}

Component *getComponent()
{
	return new MobilTestComp();
}

void releaseComponent(Component *com)
{
	delete com;
}

#else
extern "C"
{
	Component *getComponent();
	void releaseComponent(Component *com);
}
Component *getComponent()
{
	return new MobilTestComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

