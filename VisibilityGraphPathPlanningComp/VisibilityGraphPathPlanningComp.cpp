
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "VisibilityGraphPathPlanningComp.h"

//#include <limits>
//
// constructor declaration
//
VisibilityGraphPathPlanningComp::VisibilityGraphPathPlanningComp()
{
	ptrGlobalMapService = NULL;

	error = 0;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
VisibilityGraphPathPlanningComp::VisibilityGraphPathPlanningComp(const std::string &name):Component(name)
{
	ptrGlobalMapService = NULL;

	error = 0;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

VisibilityGraphPathPlanningComp::~VisibilityGraphPathPlanningComp() {
}

std::vector<OPRoS::MobilePositionData> VisibilityGraphPathPlanningComp::FindPath(OPRoS::MobilePositionData startPosition,OPRoS::MobilePositionData endPosition)
{
	std::cout<<"VisibilityGraphPathPlanningComp::FindPath()"<<std::endl;
	//user code hear
	std::vector<OPRoS::MobilePositionData> path;

	convexNode.clear();

	error = 0;
	lastError = OPROS_SUCCESS;

	if (ptrGlobalMapService == NULL) {
		error = -1;
		return path;
	}

	map = ptrGlobalMapService->GetBinaryMap();
	mapResolution = ptrGlobalMapService->GetMapCellSize();
	mapWidth = ptrGlobalMapService->GetMapWidth();
	mapHeight = ptrGlobalMapService->GetMapHeight();
	mapStartX = ptrGlobalMapService->GetMapStartX();
	mapStartY = ptrGlobalMapService->GetMapStartY();

	if (map.size() == 0) {
		error = -1;
		return path;
	}

	iStartPositionX = floor((startPosition.x - mapStartX)/mapResolution);
	iStartPositionY = floor((startPosition.y - mapStartY)/mapResolution);
	iEndPositionX = floor((endPosition.x - mapStartX)/mapResolution);
	iEndPositionY = floor((endPosition.y - mapStartY)/mapResolution);

	std::pair<bool, OPRoS::MobilePositionData> exPath1 (map[iStartPositionX][iStartPositionY], startPosition);
	std::pair<bool, OPRoS::MobilePositionData> exPath2 (map[iEndPositionX][iEndPositionY], endPosition);

	if (!(FindNearestPoint(startPosition, iStartPositionX, iStartPositionY) && FindNearestPoint(endPosition, iEndPositionX, iEndPositionY))) {
		error = -1;
		return path;
	}

	FindAllCorner ();

	if (2 <= convexNode.size()) {
		if (0 < FindAllPossibleLink ()) {
			if (SpreadToGoal ()) {
				if (exPath1.first) {
					path.push_back(exPath1.second);
				}

				TraceShortestPath(path);

				path[0].theta = endPosition.theta;
				path.resize(path.size()-1);
				std::reverse(path.begin(), path.end());

				if (exPath2.first) {
					path.push_back(exPath2.second);
				}

				return path;
			}
		}
	}

	error = -1;
	return path;
}

bool VisibilityGraphPathPlanningComp::FindNearestPoint (OPRoS::MobilePositionData &position, int &iPositionX, int &iPositionY)
{
	std::cout<<"VisibilityGraphPathPlanningComp::FindNearestPoint()"<<std::endl;

	iPositionX = floor((position.x - mapStartX)/mapResolution);
	iPositionY = floor((position.y - mapStartY)/mapResolution);

	int n=0;
	int bestX = 0, bestY = 0;
	double bestD = (std::numeric_limits<double>::max)();
	bool isFound = false;

	while (!isFound && n<(mapWidth > mapHeight ? (int)map.size() : (int)map[0].size())) {
		int dx, dy;

		dy = -n;
		if (iPositionY + dy >= 0 && iPositionY + dy < (int)map[0].size()) {
			for (dx=-n; dx<=n; ++dx) {
				if (iPositionX + dx >= 0 && iPositionX + dx < (int)map.size() && !map[iPositionX+dx][iPositionY+dy]) {
					double d = dx*dx + dy*dy;
					if (d < bestD) {
						bestX = dx;
						bestY = dy;
						isFound = true;
					}
				}
			}
		}

		dy = n;
		if (iPositionY + dy >= 0 && iPositionY + dy < (int)map[0].size()) {
			for (dx=-n; dx<=n; ++dx) {
				if (iPositionX + dx >= 0 && iPositionX + dx < (int)map.size() && !map[iPositionX+dx][iPositionY+dy]) {
					double d = dx*dx + dy*dy;
					if (d < bestD) {
						bestX = dx;
						bestY = dy;
						isFound = true;
					}
				}
			}
		}

		dx = -n;
		if (iPositionX + dx >= 0 && iPositionX + dx < (int)map.size()) {
			for (dy=-n+1; dy<=n-1; ++dy) {
				if (iPositionY + dy >= 0 && iPositionY + dy < (int)map[0].size() && !map[iPositionX+dx][iPositionY+dy]) {
					double d = dx*dx + dy*dy;
					if (d < bestD) {
						bestX = dx;
						bestY = dy;
						isFound = true;
					}
				}
			}
		}

		dx = n;
		if (iPositionX + dx >= 0 && iPositionX + dx < (int)map.size()) {
			for (dy=-n+1; dy<=n-1; ++dy) {
				if (iPositionY + dy >= 0 && iPositionY + dy < (int)map[0].size() && !map[iPositionX+dx][iPositionY+dy]) {
					double d = dx*dx + dy*dy;
					if (d < bestD) {
						bestX = dx;
						bestY = dy;
						isFound = true;
					}
				}
			}
		}

		++n;
	}

	if (!isFound) {
		return false;
	}

	iPositionX += bestX;
	iPositionY += bestY;
	position.x = (iPositionX + 0.5) * mapResolution + mapStartX;
	position.y = (iPositionY + 0.5) * mapResolution + mapStartY;

	return true;
}

void VisibilityGraphPathPlanningComp::FindAllCorner ()
{
	std::cout<<"VisibilityGraphPathPlanningComp::FindAllCorner()"<<std::endl;

	convexNode.push_back(sNode (iStartPositionX, iStartPositionY));
	convexNode.push_back(sNode (iEndPositionX, iEndPositionY));

	for (unsigned int ix = 0; ix < map.size()-1; ++ix) {
		for (unsigned int iy = 0; iy < map[0].size()-1; ++iy) {
			bool cell00 = map[ix][iy];
			bool cell01 = map[ix][iy+1];
			bool cell10 = map[ix+1][iy];
			bool cell11 = map[ix+1][iy+1];

			if (!cell00 && !cell01 && !cell10 && cell11) {
				convexNode.push_back (sNode (ix, iy));
			} else if (!cell00 && !cell01 && cell10 && !cell11) {
				convexNode.push_back (sNode (ix+1, iy));
			} else if (!cell00 && cell01 && !cell10 && !cell11) {
				convexNode.push_back (sNode (ix, iy+1));
			} else if (cell00 && !cell01 && !cell10 && !cell11) {
				convexNode.push_back (sNode (ix+1, iy+1));
			}
			int x = convexNode.back().x;
			int y = convexNode.back().y;
			convexNode.back().heuristicCostToEnd = weightTranslation * sqrt((double)(x-iEndPositionX)*(double)(x-iEndPositionX) + (double)(y-iEndPositionX)*(double)(y-iEndPositionX)) * mapResolution;
		}
	}
}

unsigned int VisibilityGraphPathPlanningComp::FindAllPossibleLink ()
{
	std::cout<<"VisibilityGraphPathPlanningComp::FindAllPossibleLink()"<<std::endl;

	unsigned int n = 0;

	for (unsigned int i=0; i<convexNode.size()-1; ++i) {
		int ix = convexNode[i].x;
		int iy = convexNode[i].y;

		for (unsigned int j=i+1; j<convexNode.size(); ++j) {
			int jx = convexNode[j].x;
			int jy = convexNode[j].y;

			if (!IsIntersect(ix, iy, jx, jy)) {
				sRoute r;

				r.distance = sqrt((double)(ix-jx)*(double)(ix-jx) + (double)(iy-jy)*(double)(iy-jy)) * mapResolution;

				r.connectedNode = &convexNode[j];
				convexNode[i].route.push_back (r);

				r.connectedNode = &convexNode[i];
				convexNode[j].route.push_back (r);

				++n;
			}
		}
	}

	return n;
}

bool VisibilityGraphPathPlanningComp::SpreadToGoal ()
{
	std::cout<<"VisibilityGraphPathPlanningComp::SpreadToGoal()"<<std::endl;

	std::vector<sNode *> openSet;

	convexNode[0].costFromStart = 0;
	openSet.push_back(&convexNode[0]);
	convexNode[0].isOpened = true;

	while (!openSet.empty ()) {
		std::sort(openSet.begin(), openSet.end(), [](sNode* a, sNode* b) -> bool { return (a->costFromStart + a->heuristicCostToEnd) < (b->costFromStart + b->heuristicCostToEnd); });
		sNode *currentNode = openSet[0];
		if (currentNode == &convexNode[1]) {
			return true;
		}

		openSet.erase(openSet.begin());
		currentNode->isOpened = false;
		currentNode->isClosed = true;

		for (unsigned int i=0; i<currentNode->route.size(); ++i) {
			sNode *neighborNode = currentNode->route[i].connectedNode;
			if (neighborNode->isClosed) {
				continue;
			}

			double cost = 0;
			if (currentNode->cameFrom != nullptr) {
				cost = currentNode->costFromStart + weightTranslation * currentNode->route[i].distance + weightRotation * fabs(DeltaRad(atan2((double)(currentNode->y - currentNode->cameFrom->y), (double)(currentNode->x - currentNode->cameFrom->x)), atan2((double)(neighborNode->y - currentNode->y), (double)(neighborNode->x - currentNode->x))));
			}

			if (!neighborNode->isOpened || cost < neighborNode->costFromStart) {
				neighborNode->cameFrom = currentNode;
				neighborNode->costFromStart = cost;

				if (!neighborNode->isOpened) {
					openSet.push_back(neighborNode);
					neighborNode->isOpened = true;
				}
			}
		}
	}

	return false;
}

void VisibilityGraphPathPlanningComp::TraceShortestPath (std::vector<OPRoS::MobilePositionData> &path)
{
	std::cout<<"VisibilityGraphPathPlanningComp::TraceShortestPath()"<<std::endl;

	sNode *cp = &convexNode[1];

	while (cp != nullptr) {
		path.push_back(OPRoS::MobilePositionData ((cp->x+0.5) * mapResolution + mapStartX, (cp->y+0.5) * mapResolution + mapStartY, 0));
		cp = cp->cameFrom;
	}
}

bool VisibilityGraphPathPlanningComp::IsIntersect(const int p1x, const int p1y, const int p2x, const int p2y)
{
	//std::cout<<"VisibilityGraphPathPlanningComp::IsIntersect()"<<std::endl;

	int pdx = p2x - p1x;
	int pdy = p2y - p1y;
	int pcx = p1x;
	int pcy = p1y;

	double dx = pdx * mapResolution;
	double dy = pdy * mapResolution;
	double cx = (p1x+0.5) * mapResolution;
	double cy = (p1y+0.5) * mapResolution;

	int dirx = pdx>0 ? 1 : (pdx<0 ? -1 : 0);
	int diry = pdy>0 ? 1 : (pdy<0 ? -1 : 0);

	if (std::abs(pdx) <= std::abs(pdy)) {
		if (diry==0) {
			if (map[pcx][pcy]) {
				return true;
			}
		} else {
			while (diry>0 ? (floor(cy/mapResolution) < p2y) : ceil(cy/mapResolution)-1 > p2y) {
				double desx = (((diry>0 ? floor(cy/mapResolution) : ceil(cy/mapResolution)) + diry) * mapResolution - cy) * dx / dy + cx;
				int pdesx = floor(desx/mapResolution);

				while (pcx*dirx < pdesx*dirx) {
					if (map[pcx][pcy]) {
						return true;
					}
					pcx += dirx;
				}
				if (map[pcx][pcy]) {
					return true;
				}

				pcx = pdesx;
				pcy += diry;
				cx = desx;
				cy = pcy * mapResolution;
			}
			while (pcx*dirx < p2x*dirx) {
				if (map[pcx][pcy]) {
					return true;
				}
				pcx += dirx;
			}
			if (map[pcx][pcy]) {
				return true;
			}
		}
	} else {
		if (dirx==0) {
			if (map[pcx][pcy]) {
				return true;
			}
		} else {
			while (dirx>0 ? (floor(cx/mapResolution) < p2x) : ceil(cx/mapResolution)-1 > p2x) {
				double desy = (((dirx>0 ? floor(cx/mapResolution) : ceil(cx/mapResolution)) + dirx) * mapResolution - cx) * dy / dx + cy;
				int pdesy = floor(desy/mapResolution);

				while (pcy*diry < pdesy*diry) {
					if (map[pcx][pcy]) {
						return true;
					}
					pcy += diry;
				}
				if (map[pcx][pcy]) {
					return true;
				}

				pcy = pdesy;
				pcx += dirx;
				cy = desy;
				cx = pcx * mapResolution;
			}
			while (pcy*diry < p2y*diry) {
				if (map[pcx][pcy]) {
					return true;
				}
				pcy += diry;
			}
			if (map[pcx][pcy]) {
				return true;
			}
		}
	}


	return false;
}

ReturnType VisibilityGraphPathPlanningComp::GetError()
{
	//user code hear
	return lastError = OPROS_SUCCESS;
}

OPRoS::Property VisibilityGraphPathPlanningComp::GetProperty()
{
	//user code hear
	error = 0;

	return parameter;
}

ReturnType VisibilityGraphPathPlanningComp::SetProperty(OPRoS::Property parameter)
{
	//user code hear
	this->parameter = parameter;

	return lastError = OPROS_SUCCESS;
}


void VisibilityGraphPathPlanningComp::portSetup() {
	ptrGlobalMapService=new GlobalMapServiceRequired();
	addPort("GlobalMapService",ptrGlobalMapService);

	ProvidedServicePort *pa1;
	pa1=new PathPlanningServiceProvided(this);
	addPort("PathPlanningService",pa1);



	// export variable setup


}

// Call back Declaration
ReturnType VisibilityGraphPathPlanningComp::onInitialize()
{
	// user code here
	std::cout<<"VisibilityGraphPathPlanningComp::onInitialize()"<<std::endl;

	parameter.SetProperty(getPropertyMap());

	error = 0;

	weightTranslation = 1;
	weightRotation = 0;

	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onStart()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType VisibilityGraphPathPlanningComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onExecute()
{
	// user code here
	return OPROS_SUCCESS;
}
	
ReturnType VisibilityGraphPathPlanningComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VisibilityGraphPathPlanningComp::onPeriodChanged()
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
	return new VisibilityGraphPathPlanningComp();
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
	return new VisibilityGraphPathPlanningComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

