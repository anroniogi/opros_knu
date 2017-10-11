#ifndef _LaserScannerComp_COMPONENT_H
#define _LaserScannerComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */
#include <Component.h>
#include <InputDataPort.h>
#include <OutputDataPort.h>
#include <InputEventPort.h>
#include <OutputEventPort.h>
#include <Event.h>
#include <OPRoSTypes.h>

#include "LaserScannerServiceProvided.h"
#include "device/LaserRangeFinder.h"
#include "device/OprosLock.h"

class LaserScannerComp : public Component, public ILaserScannerService
{
protected:
	//	Data Port
	OutputDataPort< std::vector<OPRoS::Float64Array> > laserScannerData;

	//	Service Port
	ILaserScannerService *ptrLaserScannerService;

	//	Shared(Dynamic Linked) Library's Handle
	OprosDeviceHandle hOprosAPI;

	//	Last Error
	ReturnType lastError;

	//	API's Handle
	LaserRangeFinder *laserScanner;

	OprosLock lock;

public:
	virtual ReturnType SetProperty(OPRoS::Property parameter);
	virtual OPRoS::Property GetProperty();
	virtual ReturnType GetError();
	virtual ReturnType Enable();
	virtual ReturnType Disable();
	virtual std::vector<OPRoS::Float64Array> GetSensorValue();

public:
	LaserScannerComp();
	LaserScannerComp(const std::string &compId);
	virtual ~LaserScannerComp();
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

