
#ifndef _VisibilityGraphPathPlanningComp_COMPONENT_H
#define _VisibilityGraphPathPlanningComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "device/OprosMath.h"

#include "PathPlanningServiceProvided.h"
#include "GlobalMapServiceRequired.h"

#include <limits>
#include <algorithm>

class VisibilityGraphPathPlanningComp: public Component
	,public IPathPlanningService
{
protected:
// service
// method for required
	GlobalMapServiceRequired *ptrGlobalMapService;

public:
virtual ReturnType SetProperty(OPRoS::Property parameter);
virtual OPRoS::Property GetProperty();
virtual ReturnType GetError();
virtual std::vector< OPRoS::MobilePositionData > FindPath(OPRoS::MobilePositionData startPosition,OPRoS::MobilePositionData endPosition);


protected:
// service
// method for provider
	IPathPlanningService *ptrPathPlanningService;

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation
	

public:
	VisibilityGraphPathPlanningComp();
	VisibilityGraphPathPlanningComp(const std::string &compId);
	virtual ~VisibilityGraphPathPlanningComp();
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
	struct sNode;
	struct sRoute {
		double distance;
		sNode *connectedNode;
	};
	struct sNode {
		int x, y;
		double costFromStart;
		double heuristicCostToEnd;
		bool isOpened;
		bool isClosed;
		sNode *cameFrom;
		std::vector<sRoute> route;

		sNode (int x, int y) : x(x), y(y), costFromStart(0), heuristicCostToEnd(0), isOpened(false), isClosed(false), cameFrom(nullptr) { }
	};

	std::vector<sNode> convexNode;

	OPRoS::Property parameter;

	int error;
	ReturnType			lastError;

	std::vector< std::vector<bool> > map;
	double mapResolution;
	double mapWidth;
	double mapHeight;
	double mapStartX;
	double mapStartY;
	int iStartPositionX;
	int iStartPositionY;
	int iEndPositionX;
	int iEndPositionY;

	double weightTranslation;
	double weightRotation;	// is related with angular and linear velocity

	bool FindNearestPoint (OPRoS::MobilePositionData &position, int &iPositionX, int &iPositionY);

	void FindAllCorner ();

	unsigned int FindAllPossibleLink ();

	bool SpreadToGoal ();

	void TraceShortestPath (std::vector<OPRoS::MobilePositionData> &path);

	bool IsIntersect(const int i1x, const int i1y, const int i2x, const int i2y);
};

#endif

