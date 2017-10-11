
#ifndef _SLAMComp_COMPONENT_H
#define _SLAMComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include <memory>
#include <vector>
#include <algorithm>
#include <thread>  //kitech

#include "MobileControllerServiceRequired.h"
#include "LaserScannerServiceRequired.h"
#include "SLAMServiceProvided.h"
#include "GridBasedGlobalMap.h"

#include "device/OprosMath.h"
#include "device/MobilePositionData.h"

#define DEBUG 0
#if DEBUG
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#endif

#define SHOWALL 0


class SLAMComp: public Component
	,public ISLAMService
{
protected:
// service
// method for provider
	ISLAMService *ptrSLAMService;

public:
virtual ReturnType SetProperty(OPRoS::Property parameter);
virtual OPRoS::Property GetProperty();
virtual ReturnType GetError();
virtual bool LoadMapFile(std::string fileName);
virtual bool SaveMapFile(std::string fileName);
virtual double GetMapCellSize();
virtual double GetMapStartX();
virtual double GetMapStartY();
virtual double GetMapWidth();
virtual double GetMapHeight();
virtual double GetCellOccProb(double x,double y);
virtual bool IsIn(double x,double y);
virtual void ReStartSLAM();
virtual OPRoS::MobilePositionData GetPosition();
virtual std::vector< std::vector< double > > GetMap();

protected:
// service
// method for required
	LaserScannerServiceRequired *ptrLaserScannerService;

protected:
// service
// method for required
	MobileControllerServiceRequired *ptrMobileControllerService;

protected:
// data


//event


// method for provider
	

// method for required
	

// symbol value generation
	

public:
	SLAMComp();
	SLAMComp(const std::string &compId);
	virtual ~SLAMComp();
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

public:
	struct VirtualRobot {
		VirtualRobot() {
			logLikelihood = weight = weightSum = 0;
			position.x = position.y = position.theta = 0;
		}
		double logLikelihood;
		OPRoS::MobilePositionData position;
		std::shared_ptr<GridBasedGlobalMap> map;

		double weight;
		double weightSum;

		//std::vector<OPRoS::MobilePositionData> positionHistory;
	};

	typedef std::pair<OPRoS::MobilePositionData, bool> VisitedCell;
	typedef std::vector<VisitedCell> VisitedCellList;
	typedef std::vector< std::vector< double > > MapT;

private:
	OPRoS::Property parameter;

	int error;
	ReturnType lastError;

	bool LoadProperty();

	// SLAM result
	std::shared_ptr<GridBasedGlobalMap> globalMap;
	OPRoS::MobilePositionData currentPosition;

	// prediction parameter
	OPRoS::MobilePositionData previousPosition;
	double a1, a2, a3, a4;

	// measurement parameter
	double startAngle;
	double endAngle;
	double minRange;
	double maxRange;
	unsigned int sensorCount;
	double sensorVariance;
	OPRoS::MobilePositionData sensorPosition;
	OPRoS::MobilePositionData variance;
	double minRatioNumberValidPoint;

	// particle filter parameter
	std::vector<VirtualRobot> particles;
	unsigned int NumberOfParticles;
	double effectiveNumber;
	double resamplingThreshold;

	// SLAM parameters
	double mapResolution;
	double mapLogLikelihoodThreshold;
	double minCellLogLikelihood;
	double maxCellLogLikelihood;
	double logLikelihood_occupied;
	double logLikelihood_free;
	std::vector< VisitedCellList > visitedCellLists;
	unsigned int searchWindowSize;
	bool doPrediction;
	double minLinearDistance;
	double minAngularDistance;
	bool isInitialized;

	// scan matching parameter
	bool useScanMatching;
	double maxMatchingLinearStepLength;
	double maxMatchingAngularStepLength;
	unsigned int matchingFineDegree;
	// double minMatchingLoglikelihoodLevel;

	void DoSLAMOneCycle();
	bool Localize();
	bool Mapping ();
	bool Predict (OPRoS::MobilePositionData position);
	bool Update (std::vector<double> sensorValue);
	double GetLogLikelihood (const VirtualRobot &vr, const std::vector<double> &laserData, VisitedCellList& visitedCellList);
	double GetLogLikelihood (const VirtualRobot &vr, const std::vector<double> &laserData);
	void GetVisitedCellList(const VirtualRobot &vr, const std::vector<double> &laserData, VisitedCellList& visitedCellList);
	void Resampling ();
	void CalculateWeights();
	void Raycast (const VirtualRobot &vr, const OPRoS::MobilePositionData &endPoint, VisitedCellList &visitedCellList);
	double EndPoint(const VirtualRobot &vr, const OPRoS::MobilePositionData &endPoint);
	void SelectBestParticle();
	void ScanMatching(VirtualRobot &vr, const std::vector<double> &laserData);

	void MappingOne (unsigned int i);
	void UpdateOne (std::vector<double> sensorValue, unsigned int i);

#if DEBUG
	cv::Mat im;
	void line (cv::Mat &im, OPRoS::MobilePositionData p1, OPRoS::MobilePositionData p2, int thick, unsigned char rgb[]);
	void mark (cv::Mat &im, int x, int y, int thick, unsigned char rgb[]);
	void drawmap(GridBasedGlobalMap &map, OPRoS::MobilePositionData position, unsigned int index);
	std::vector<double> lastLaserData;
	int magnifyingScale;
#endif
};

#endif

