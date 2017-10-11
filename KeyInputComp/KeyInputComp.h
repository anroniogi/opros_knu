
#ifndef _KeyInputComp_COMPONENT_H
#define _KeyInputComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>
//#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

#include "KeyInputServiceProvided.h"

//#include "OPRoS::Int32.h"

class KeyInputComp: public Component
	,public IKeyInputService
{
protected:
// service
// method for provider
	IKeyInputService *ptrKeyInputService;

protected:
// service
// method for provider
/*	IKeyInputService *ptrKeyInputService;*/

protected:
//data
	OutputDataPort< OPRoS::Int16 > OutputKeyInputData;

protected:
// service
// method for provider
/*	IKeyInputService *ptrKeyInputService;*/

protected:
//data
/*	OutputDataPort< OPRoS::Int32 > OutputKeyInputData;*/

protected:
// service
// method for provider
/*	IKeyInputService *ptrKeyInputService;*/

protected:
// service
// method for provider
/*	IKeyInputService *ptrKeyInputService;*/

public:
virtual ReturnType SetProperty(OPRoS::Property parameter);
virtual OPRoS::Property GetProperty();
virtual ReturnType GetError();
virtual ReturnType Enable();
virtual ReturnType Disable();
virtual OPRoS::Int16 GetKeyInput();

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
OPRoS::Property parameter;

//	Last Error
	ReturnType lastError;
	int key;
	

public:
	KeyInputComp();
	KeyInputComp(const std::string &compId);
	virtual ~KeyInputComp();
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

