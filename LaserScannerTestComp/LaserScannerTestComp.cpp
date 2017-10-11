
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "LaserScannerTestComp.h"

//
// constructor declaration
//
LaserScannerTestComp::LaserScannerTestComp()
{
	ptrLaserScannerService = NULL;


	
	portSetup();
}

//
// constructor declaration (with name)
//
LaserScannerTestComp::LaserScannerTestComp(const std::string &name):Component(name)
{
	ptrLaserScannerService = NULL;


	
	portSetup();
}

//
// destructor declaration
//

LaserScannerTestComp::~LaserScannerTestComp() {
}

void LaserScannerTestComp::portSetup() {
	ptrLaserScannerService=new LaserScannerServiceRequired();
	addPort("LaserScannerService",ptrLaserScannerService);




	// export variable setup


}

// Call back Declaration
ReturnType LaserScannerTestComp::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType LaserScannerTestComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onExecute()
{
	// user code heree

	std::vector<OPRoS::Float64Array> vval;
	OPRoS::Float64Array fval;
	vval=ptrLaserScannerService->GetSensorValue();

std::cout<<"LASERSCANNERTESTCOMP ONEXECUTE TEST02"<<std::endl;
//std::cout<<"val="<<vval.size()<<std::endl;
	fval=vval[0].data;
std::cout<<"fval="<<fval.data.size()<<std::endl;
	std::vector<int>::size_type sz = fval.data.size();
	for (unsigned i=0; i<sz; i++)
		std::cout << ' ' << fval.data[i];
	std::cout << '\n';

	return OPROS_SUCCESS;
}
	
ReturnType LaserScannerTestComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType LaserScannerTestComp::onPeriodChanged()
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
	return new LaserScannerTestComp();
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
	return new LaserScannerTestComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

