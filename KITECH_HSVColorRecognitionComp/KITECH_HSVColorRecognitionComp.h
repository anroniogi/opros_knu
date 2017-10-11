
#ifndef _KITECH_HSVColorRecognitionComp_COMPONENT_H
#define _KITECH_HSVColorRecognitionComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include <device/ColorRange.h>


#include "VisionRecognitionServiceProvided.h"

class KITECH_HSVColorRecognitionComp: public Component
	,public IVisionRecognitionService
{
protected:
// service
// method for provider
	IVisionRecognitionService *ptrVisionRecognitionService;

public:
virtual ReturnType SetProperty(OPRoS::Property parameter);
virtual OPRoS::Property GetProperty();
virtual ReturnType GetError();
virtual ReturnType Enable();
virtual ReturnType Disable();
virtual std::vector<OPRoS::VisionRecognitionResultData> Recognize(std::vector<unsigned char> image,int width,int height,int pixelBytes);
protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
OPRoS::Property parameter;

std::vector<OPRoS::ColorRange>	_colorRange;

public:
	KITECH_HSVColorRecognitionComp();
	KITECH_HSVColorRecognitionComp(const std::string &compId);
	virtual ~KITECH_HSVColorRecognitionComp();
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

	void GetDataFromDB(const char* database);
	void SetDataToDB(const char* database);

};

#endif

