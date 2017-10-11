
#ifndef _CamViewer_COMPONENT_H
#define _CamViewer_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "device/CameraData.h"
#include "opencv2/opencv.hpp"

class CamViewer: public Component
{
protected:
//data
	InputDataPort< OPRoS::CameraData > imageData;
	OPRoS::CameraData _img;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	CamViewer();
	CamViewer(const std::string &compId);
	virtual ~CamViewer();
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

