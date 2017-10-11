
#ifndef _ControllComp_COMPONENT_H
#define _ControllComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>



#include "KeyInputServiceRequired.h"



#include "LaserScannerServiceRequired.h"


class ControllComp: public Component
{
protected:
// service
// method for required
	LaserScannerServiceRequired *ptrLaserScannerService;

protected:
// monitor variables
	int m_counter;

protected:
// service
// method for required
	KeyInputServiceRequired *ptrKeyInputService;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	ControllComp();
	ControllComp(const std::string &compId);
	virtual ~ControllComp();
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

