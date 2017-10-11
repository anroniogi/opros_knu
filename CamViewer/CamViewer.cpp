
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "CamViewer.h"

//
// constructor declaration
//
CamViewer::CamViewer()
	:imageData(OPROS_LAST,1)
{

	
	portSetup();
}

//
// constructor declaration (with name)
//
CamViewer::CamViewer(const std::string &name):Component(name)
	,imageData(OPROS_LAST,1)
{

	
	portSetup();
}

//
// destructor declaration
//

CamViewer::~CamViewer() {
}

void CamViewer::portSetup() {
//data port setup
	addPort("imageData", &imageData);




	// export variable setup


}

// Call back Declaration
ReturnType CamViewer::onInitialize()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType CamViewer::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onExecute()
{
	// user code here
	opros_any *pData = imageData.pop();
	if (pData == NULL) return OPROS_CALL_API_ERROR;
	
	_img = imageData.getContent(*pData);
	if (_img.format != 0 && _img.format != 2) return OPROS_CALL_API_ERROR;

	cv::Mat cvImg(_img.height, _img.width, (_img.format == 0) ? CV_8UC1 : CV_8UC3, _img.data.data());
	cv::imshow("", cvImg);
	cv::waitKey(1);

	delete pData;
	
	return OPROS_SUCCESS;
}
	
ReturnType CamViewer::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType CamViewer::onPeriodChanged()
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
	return new CamViewer();
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
	return new CamViewer();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

