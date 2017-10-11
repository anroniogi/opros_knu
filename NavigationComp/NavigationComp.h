
#ifndef _NavigationComp_COMPONENT_H
#define _NavigationComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

using std::vector;

#include "device/MobilePositionData.h"
#include "device/MobileVelocityData.h"
#include "device/OprosMath.h"

#include <thread> //kitech
#include <gtk/gtk.h>
#include <gdk/gdk.h>
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <cairo.h>

#include "SLAMServiceRequired.h"
#include "GlobalMapServiceProvided.h"
#include "PathPlanningServiceRequired.h"



#include "ObstacleAvoidanceServiceRequired.h"


class NavigationComp: public Component
	,public IGlobalMapService
{
protected:
//data
	OutputDataPort< OPRoS::MobileVelocityData > velocity;

protected:
//data
	/*OutputDataPort< OPRoS::MobileVelocityData > velocity;*/

protected:
//data
/*	OutputDataPort< OPRoS::MobileVelocityData > velocitydata;*/

protected:
//data
/*	OutputDataPort< OPRoS::MobileVelocityData > velocitydata;*/

protected:
// service
// method for required
	ObstacleAvoidanceServiceRequired *ptrObstacleAvoidanceService;

protected:
// service
// method for required
	PathPlanningServiceRequired *ptrPathPlanningService;

protected:
// service
// method for provider
	IGlobalMapService *ptrGlobalMapService;

public:
virtual double GetMapCellSize();
virtual double GetMapStartX();
virtual double GetMapStartY();
virtual double GetMapWidth();
virtual double GetMapHeight();
virtual std::vector< std::vector< bool > > GetBinaryMap();

protected:
// service
// method for required
	SLAMServiceRequired *ptrSLAMService;

protected:
//data
/*	OutputDataPort< OPRoS::MobileVelocityData > velocity;*/

protected:
// data


//event


// method for provider


// method for required



// symbol value generation


public:
	NavigationComp();
	NavigationComp(const std::string &compId);
	virtual ~NavigationComp();
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

private:
	enum eNavigationState {
		NS_IDLE, NS_NAVIGATION_TO, NS_TURN, NS_STOP
	} navigationStep;

	OPRoS::MobileVelocityData currentVelocity;
	OPRoS::MobileVelocityData previousVelocity;
	OPRoS::MobileVelocityData stepVelocity;
	OPRoS::MobileVelocityData autoVelocity;

	std::vector<OPRoS::MobilePositionData> targetPositionSet;
	OPRoS::MobilePositionData currentTargetPosition;
	bool useTargetPosition;
	bool isLButtonDragging;
	OPRoS::MobilePositionData targetPosition;
	bool addTarget;
	std::vector<OPRoS::MobilePositionData> currentPath;
	OPRoS::MobilePositionData currentSubTargetPosition;

	int mapImageWidth;
	int mapImageHeight;
	int mapImageOffsetX;
	int mapImageOffsetY;

	void CalculateVelocity();

	std::vector< std::vector<double> > currentMap;
	double mapStartX;
	double mapStartY;
	double mapWidth;
	double mapHeight;
	OPRoS::MobilePositionData currentPosition;
	double mapResolution;

	double robotRadius;
	double mapOccProbThreshold;
	bool safeMode;

	double magnifyingScale;
	bool ctrlPressed;
	bool showConfigSpace;
	void ProcessGUI();
	static gboolean OnKeyPress(GtkWindow *window, GdkEventKey *event, gpointer data);
	static gboolean OnKeyRelease(GtkWindow *window, GdkEventKey *event, gpointer data);
	static gboolean OnMousePress(GtkWindow *window, GdkEventButton *event, gpointer data);
	static gboolean OnMouseDrag(GtkWindow *window, GdkEventMotion *event, gpointer data);
	static gboolean OnMouseRelease(GtkWindow *window, GdkEventButton *event, gpointer data);
	static gboolean OnDraw(GtkWindow *window, cairo_t *cr, gpointer data);
	static gboolean Redraw(gpointer data);
	static gboolean OnButtonClick(GtkButton *button, gpointer data);
	void ClearAutoNaviInfo();

	void ControlSpeed();
};

void onMouse(int event, int x, int y, int flags, void *param);

#endif


#ifndef _NavigationComp_COMPONENT_H
#define _NavigationComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *
 */

#include <OPRoSInclude.h>



#include "SLAMServiceRequired.h"



#include "PathPlanningServiceRequired.h"



#include "ObstacleAvoidanceServiceRequired.h"


#include "GlobalMapServiceProvided.h"

class NavigationComp: public Component
	,public IGlobalMapService
{
protected:
// service
// method for provider
	IGlobalMapService *ptrGlobalMapService;

protected:
// service
// method for required
	ObstacleAvoidanceServiceRequired *ptrObstacleAvoidanceService;

protected:
// service
// method for required
	PathPlanningServiceRequired *ptrPathPlanningService;

protected:
// service
// method for required
	SLAMServiceRequired *ptrSLAMService;

public:
virtual double GetMapCellSize();
virtual double GetMapStartX();
virtual double GetMapStartY();
virtual double GetMapWidth();
virtual double GetMapHeight();
virtual std::vector< std::vector< bool > > GetBinaryMap();

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	NavigationComp();
	NavigationComp(const std::string &compId);
	virtual ~NavigationComp();
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

