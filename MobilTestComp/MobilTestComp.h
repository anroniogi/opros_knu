
#ifndef _MobilTestComp_COMPONENT_H
#define _MobilTestComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>
//#include <MobileController.h>


#include "MobileControllerServiceRequired.h"


class MobilTestComp: public Component
{
protected:
// service
// method for required
	MobileControllerServiceRequired *ptrMobileControllerService;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	MobilTestComp();
	MobilTestComp(const std::string &compId);
	virtual ~MobilTestComp();
	virtual void portSetup();

protected:
	virtual ReturnType onInitialize();
	virtual ReturnType onStart();
	virtual ReturnType onStop();
	virtual ReturnType onReset();
	virtual ReturnType onError();
	virtual ReturnType onRecover();
	virtual ReturnType onDestroy();

public:
	virtual ReturnType onEvent(Event *evt);
	virtual ReturnType onExecute();
	virtual ReturnType onUpdated();
	virtual ReturnType onPeriodChanged();


};

#endif

