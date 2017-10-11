/*************************************************************

 file: MobileControllerComp.cpp
 author: M.S. Kim
 begin: September 2015
 email: opros.contact@gmail.com

 - Updated based on OPRoS Component Service API 0.315

***************************************************************/


#ifndef _MobileControllerComp_COMPONENT_H
#define _MobileControllerComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "device/OprosPrintMessage.h"
#include "device/MobileController.h"
#include "MobileControllerServiceProvided.h"

class MobileControllerComp: public Component
	,public IMobileControllerService
{
protected:
//data
	InputDataPort< OPRoS::MobileVelocityData > velocity;

protected:
// service
// method for provider
	IMobileControllerService *ptrMobileControllerService;

protected:
	OprosDeviceHandle	hOprosAPI;
	ReturnType			lastError;
	MobileController	*MobileControl;
	OPRoS::Property			m_Property;

public:
virtual ReturnType SetProperty(OPRoS::Property parameter);
virtual OPRoS::Property GetProperty();
virtual ReturnType GetError();
virtual ReturnType Enable();
virtual ReturnType Disable();
virtual std::vector<OPRoS::Int32> GetOdometry();
virtual ReturnType SetVelocity(OPRoS::MobileVelocityData velocity);
virtual ReturnType SetPosition(OPRoS::MobilePositionData position);
virtual OPRoS::MobilePositionData GetPosition();
virtual ReturnType MoveBase(float64_t distance,float64_t velocity);
virtual ReturnType RotateBase(float64_t angle,float64_t velocity);
virtual ReturnType StopBase();
virtual bool IsBaseRunning();

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	MobileControllerComp();
	MobileControllerComp(const std::string &compId);
	virtual ~MobileControllerComp();
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

