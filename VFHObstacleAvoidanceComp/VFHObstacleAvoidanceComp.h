
#ifndef _VFHObstacleAvoidanceComp_COMPONENT_H
#define _VFHObstacleAvoidanceComp_COMPONENT_H
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.0[Symbol])
 *   
 */

#include <OPRoSInclude.h>

#include "LaserScannerServiceRequired.h"
#include "ObstacleAvoidanceServiceProvided.h"

#include "device/OprosMath.h"
#include "device/OprosPrintMessage.h"

#include <limits>

class VFHObstacleAvoidanceComp: public Component
	,public IObstacleAvoidanceService
{
protected:
// service
// method for provider
	IObstacleAvoidanceService *ptrObstacleAvoidanceService;

protected:
// service
// method for required
	LaserScannerServiceRequired *ptrLaserScannerService;

public:
virtual ReturnType SetProperty(OPRoS::Property parameter);
virtual OPRoS::Property GetProperty();
virtual ReturnType SetPosition(OPRoS::MobilePositionData position);
virtual ReturnType GetError();
virtual OPRoS::MobileVelocityData Avoid(OPRoS::MobilePositionData currentPosition,OPRoS::MobilePositionData targetPosition);

protected:
// data


//event


// method for provider
	

// method for required
	


// symbol value generation


public:
	VFHObstacleAvoidanceComp();
	VFHObstacleAvoidanceComp(const std::string &compId);
	virtual ~VFHObstacleAvoidanceComp();
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
	OPRoS::Property parameter;

	int error;
	ReturnType lastError;

	bool LoadProperty();

	double weight1;
	double weight2;
	double weight3;

	double startAngle;
	double endAngle;
	unsigned int sensorCount;
	double minRange;
	double maxRange;
	double sensorVariance;	// 이거 certainty value 결정할 때 사용 가능.
	OPRoS::MobilePositionData sensorPosition;

	double cellSize;
	double maxRadius;
	std::vector<std::vector<double> > influenceTable;
	std::vector<std::vector<double> > directions;
	std::vector<std::vector<double> > enlargementAngle;
	std::vector<std::vector<double> > certaintyTable;

	unsigned int numberOfAngularSectors;
	double angularResolution;

	double robotRadius;
	double safeDistance;
	double enlargedRobotRadius;
	double a;
	double b;

	std::vector<double> sectorWeights;
	std::vector<double> polarHistogram;
	std::vector<std::pair<unsigned int, unsigned int> > activeCellIndices;

	double lowerThreshold;
	double upperThreshold;
	std::vector<bool> binaryHistogram;
	std::vector<bool> maskedPolarHistogram;

	double leftRadius;
	double rightRadius;	// 나중에 속도에 대한 함수로 설정. 그 함수의 parameter는 parameter로 설정. 속도는 navigationComp으로부터 받아.

	OPRoS::MobilePositionData currentPosition;
	OPRoS::MobilePositionData targetPosition;
	std::vector<std::pair<int, int> > bordersOfOpennings;
	unsigned int minNumberForWide;
	unsigned int lastDirection;

	unsigned int Rad2Index(double degree) {
		return ceil((degree + M_PI)/angularResolution) - 1;
	}
	double Index2Rad(int index) {
		return (index+0.5) * angularResolution - M_PI;
	}
	int DeltaIndex(int i, int j) {
		return ( abs((int)(i-j)) < abs((int)(i-j+numberOfAngularSectors)) ? (abs(i-j) < abs((int)(j-i+numberOfAngularSectors)) ? abs(i-j) : abs((int)(j-i+numberOfAngularSectors))) : (abs((int)(i-j+numberOfAngularSectors)) < abs((int)(j-i+numberOfAngularSectors)) ? abs((int)(i-j+numberOfAngularSectors)) : abs((int)(j-i+numberOfAngularSectors))));
	}

	void MakePolarHistogram(const std::vector<double> &laserData);
	void MakeMaskedPolarHistogram();
	int SelectDirection();
};

#endif

