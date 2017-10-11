
#ifndef _LaserScannerTestComp_COMPONENT_H
#define _LaserScannerTestComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>



#include "LaserScannerServiceRequired.h"


class LaserScannerTestComp: public Component
{
protected:
// service
// method for required
	LaserScannerServiceRequired *ptrLaserScannerService;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	LaserScannerTestComp();
	LaserScannerTestComp(const std::string &compId);
	virtual ~LaserScannerTestComp();
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

