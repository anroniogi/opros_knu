
/*
 *  Generated sources by OPRoS Component Generator (OCG V2.1 [Symbol,Topic])
 *  
 */

#include <OPRoSInclude.h>

#include "VFHObstacleAvoidanceComp.h"

#define DEBUG 1
#if DEBUG
#include <opencv2/core/core.hpp>
#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iomanip>
#endif

//
// constructor declaration
//
VFHObstacleAvoidanceComp::VFHObstacleAvoidanceComp()
{
	ptrLaserScannerService = NULL;

	error = 0;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// constructor declaration (with name)
//
VFHObstacleAvoidanceComp::VFHObstacleAvoidanceComp(const std::string &name):Component(name)
{
	ptrLaserScannerService = NULL;

	error = 0;
	lastError = OPROS_SUCCESS;
	
	portSetup();
}

//
// destructor declaration
//

VFHObstacleAvoidanceComp::~VFHObstacleAvoidanceComp() {
}

OPRoS::MobileVelocityData VFHObstacleAvoidanceComp::Avoid(OPRoS::MobilePositionData currentPosition,OPRoS::MobilePositionData targetPosition)
{
	std::cout<<"VFHObstacleAvoidance::Avoid()"<<std::endl;
	//user code hear
	error = 0;
	lastError = OPROS_SUCCESS;

	this->currentPosition = currentPosition;
	this->targetPosition = targetPosition;

	OPRoS::MobileVelocityData velocity;

	double hmin = 1e3;
	double vmax = 0.2;
	double wmax = DEG2RAD(90);
	double vmin = 0.05;

//	std::vector<double> laserData = ptrLaserScannerService->GetSensorValue();
	std::vector<OPRoS::Float64Array> laserData = ptrLaserScannerService->GetSensorValue();
	if (laserData.at(0).data.size()  == sensorCount) {
		MakePolarHistogram(laserData.at(0).data);
		MakeMaskedPolarHistogram();
		int selectedDirection = SelectDirection();
		if (selectedDirection != -1) {
			std::cout<<"selectedDirection  = "<<RAD2DEG(Index2Rad(selectedDirection)) <<", current = "<<currentPosition.x<<","<<currentPosition.y<<","<<RAD2DEG(currentPosition.theta)<<", target = "<<targetPosition.x<<","<<targetPosition.y<<","<<RAD2DEG(targetPosition.theta)<<std::endl;

			if (selectedDirection >= 0 && selectedDirection < (int)numberOfAngularSectors) {
				double deltaAngle = DeltaRad(Index2Rad(selectedDirection),0);
				//velocity.x = vmax * (1 - (polarHistogram[selectedDirection] < hmin ? polarHistogram[selectedDirection] : hmin) / hmin) * (1 - (fabs(deltaAngle) > wmax ? wmax : fabs(deltaAngle))/wmax) + vmin;
				velocity.x = vmin;
				velocity.theta = deltaAngle;
				//velocity.theta = velocity.x / (deltaAngle > 0 ? leftRadius : -rightRadius);
				//velocity.theta = velocity.theta > wmax ? wmax : (velocity.theta < -wmax ? -wmax : velocity.theta);
			} else {

			}
		} else {
			velocity.x = 0;
			velocity.theta = wmax;
		}
	} else {
		velocity.x = vmax;
		velocity.theta = 0;
	}

	return velocity;
}
//170825 mskim       virtual ReturnType SetPosition(OPRoS::MobilePositionData position)=0;

ReturnType VFHObstacleAvoidanceComp::SetPosition(OPRoS::MobilePositionData position)
{
	//user code hear
	//return error;
	return lastError;
}

ReturnType VFHObstacleAvoidanceComp::GetError()
{
	//user code hear
	//return error;
	return lastError;
}

OPRoS::Property VFHObstacleAvoidanceComp::GetProperty()
{
	//user code hear
	error = 0;  //kitech
	lastError = OPROS_SUCCESS;

	return parameter;
}

ReturnType VFHObstacleAvoidanceComp::SetProperty(OPRoS::Property parameter)
{
	//user code hear
	this->parameter = parameter;
	if (!LoadProperty())
		//return false; //kitech
		lastError = OPROS_PRECONDITION_NOT_MET;

	//return true;  //kitech
	return lastError;
}


void VFHObstacleAvoidanceComp::portSetup() {
	ptrLaserScannerService=new LaserScannerServiceRequired();
	addPort("LaserScannerService",ptrLaserScannerService);

	ProvidedServicePort *pa1;
	pa1=new ObstacleAvoidanceServiceProvided(this);
	addPort("ObstacleAvoidanceService",pa1);




	// export variable setup


}

// Call back Declaration
ReturnType VFHObstacleAvoidanceComp::onInitialize()
{
	// user code here
	std::cout<<"VFHObstacleAvoidanceComp::onInitialize()"<<std::endl;

	parameter.SetProperty(getPropertyMap());
	if (!LoadProperty())
		return OPROS_FIND_PROPERTY_ERROR;

	error = 0;

	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onStart()
{
	// user code here
	std::cout<<"VFHObstacleAvoidanceComp::onStart()"<<std::endl;

#if DEBUG	//밑에 두줄 주석이였는데 풀었음
	cv::namedWindow("localmap",CV_WINDOW_AUTOSIZE);
	cv::namedWindow("localmap2",CV_WINDOW_AUTOSIZE);
#endif
/*
    // kitech
	startAngle = DEG2RAD(atof(ptrLaserScannerService->GetParameter().GetValue("StartAngle").c_str()));
	endAngle = DEG2RAD(atof(ptrLaserScannerService->GetParameter().GetValue("EndAngle").c_str()));
	sensorCount = (atoi(ptrLaserScannerService->GetParameter().GetValue("EndStep").c_str()) - atoi(ptrLaserScannerService->GetParameter().GetValue("StartStep").c_str())) / atoi(ptrLaserScannerService->GetParameter().GetValue("DeltaStep").c_str()) + 1;
	minRange = atof(ptrLaserScannerService->GetParameter().GetValue("MinimumRange").c_str());
	maxRange = atof(ptrLaserScannerService->GetParameter().GetValue("MaximumRange").c_str());
	sensorVariance = atof(ptrLaserScannerService->GetParameter().GetValue("Variance").c_str());
	sensorPosition.x = atof(ptrLaserScannerService->GetParameter().GetValue("X").c_str());
	sensorPosition.y = atof(ptrLaserScannerService->GetParameter().GetValue("Y").c_str());
	sensorPosition.theta = DEG2RAD(atof(ptrLaserScannerService->GetParameter().GetValue("Yaw").c_str()));
*/

	startAngle = DEG2RAD(atof(ptrLaserScannerService->GetProperty().GetValue("StartAngle").c_str()));
	endAngle = DEG2RAD(atof(ptrLaserScannerService->GetProperty().GetValue("EndAngle").c_str()));
	sensorCount = (atoi(ptrLaserScannerService->GetProperty().GetValue("EndStep").c_str()) - atoi(ptrLaserScannerService->GetProperty().GetValue("StartStep").c_str())) / atoi(ptrLaserScannerService->GetProperty().GetValue("DeltaStep").c_str()) + 1;
	minRange = atof(ptrLaserScannerService->GetProperty().GetValue("MinimumRange").c_str());
	maxRange = atof(ptrLaserScannerService->GetProperty().GetValue("MaximumRange").c_str());
	sensorVariance = atof(ptrLaserScannerService->GetProperty().GetValue("Variance").c_str());
	sensorPosition.x = atof(ptrLaserScannerService->GetProperty().GetValue("X").c_str());
	sensorPosition.y = atof(ptrLaserScannerService->GetProperty().GetValue("Y").c_str());
	sensorPosition.theta = DEG2RAD(atof(ptrLaserScannerService->GetProperty().GetValue("Yaw").c_str()));

	//double maxRadius = (floor((maxRange + sqrt(sensorPosition.x*sensorPosition.x + sensorPosition.y*sensorPosition.y)) / cellSize) + 0.5) * cellSize;
///////////////////////
	angularResolution = 2*M_PI / numberOfAngularSectors;

	enlargedRobotRadius = robotRadius + safeDistance;
	a = maxRadius / (maxRadius - enlargedRobotRadius);
	b = a / (maxRadius);

	sectorWeights = std::vector<double>(numberOfAngularSectors, 0);
	double averageCellNumber = 0;

	int windowSize = floor(maxRadius/cellSize) * 2 + 1;
	influenceTable = std::vector<std::vector<double> >(windowSize, std::vector<double>(windowSize, 0));
	enlargementAngle = std::vector<std::vector<double> >(windowSize, std::vector<double>(windowSize, 0));
	directions = std::vector<std::vector<double> >(windowSize, std::vector<double>(windowSize, 0));
	for (int i=0; i<=(windowSize-1)/2; ++i) {
		for (int j=0; j<=(windowSize-1)/2; ++j) {
			double distance = sqrt((i - (windowSize-1)/2)*(i - (windowSize-1)/2) + (j - (windowSize-1)/2)*(j - (windowSize-1)/2)) * cellSize;

			influenceTable[i][j] = distance <= enlargedRobotRadius ? 1 : (distance > maxRadius ? 0 : a - b * distance);
			enlargementAngle[i][j] = enlargedRobotRadius < distance ? asin(enlargedRobotRadius / distance) : M_PI/2;
			directions[i][j] = atan2((j - (windowSize-1)/2),(i - (windowSize-1)/2));

			if (influenceTable[i][j] > 0) {
				++sectorWeights[Rad2Index(directions[i][j])];
				++averageCellNumber;
			}

			if (i != (windowSize-1)/2 && j != (windowSize-1)/2) {
				influenceTable[windowSize-1-i][j] = influenceTable[i][windowSize-1-j] = influenceTable[windowSize-1-i][windowSize-1-j] = influenceTable[i][j];
				enlargementAngle[windowSize-1-i][j] = enlargementAngle[i][windowSize-1-j] = enlargementAngle[windowSize-1-i][windowSize-1-j] = enlargementAngle[i][j];
				directions[windowSize-1-i][j] = atan2((j - (windowSize-1)/2),-(i - (windowSize-1)/2));
				directions[i][windowSize-1-j] = atan2(-(j - (windowSize-1)/2),(i - (windowSize-1)/2));
				directions[windowSize-1-i][windowSize-1-j] = atan2(-(j - (windowSize-1)/2),-(i - (windowSize-1)/2));

				if (influenceTable[i][j] > 0) {
					++sectorWeights[Rad2Index(directions[windowSize-1-i][j])];
					++sectorWeights[Rad2Index(directions[i][windowSize-1-j])];
					++sectorWeights[Rad2Index(directions[windowSize-1-i][windowSize-1-j])];
					averageCellNumber += 3;
				}
			} else if (i == (windowSize-1)/2 && j != (windowSize-1)/2) {
				influenceTable[i][windowSize-1-j] = influenceTable[i][j];
				enlargementAngle[i][windowSize-1-j] = enlargementAngle[i][j];
				directions[i][windowSize-1-j] = atan2(-(j - (windowSize-1)/2),(i - (windowSize-1)/2));

				if (influenceTable[i][j] > 0) {
					++sectorWeights[Rad2Index(directions[i][windowSize-1-j])];
					averageCellNumber += 1;
				}
			} else if (i != (windowSize-1)/2 && j == (windowSize-1)/2) {
				influenceTable[windowSize-1-i][j] = influenceTable[i][j];
				enlargementAngle[windowSize-1-i][j] = enlargementAngle[i][j];
				directions[windowSize-1-i][j] = atan2((j - (windowSize-1)/2),-(i - (windowSize-1)/2));

				if (influenceTable[i][j] > 0) {
					++sectorWeights[Rad2Index(directions[windowSize-1-i][j])];
					averageCellNumber += 1;
				}
			}
		}
	}

	averageCellNumber /= numberOfAngularSectors;
	for (unsigned int i=0; i<sectorWeights.size(); ++i) {
		sectorWeights[i] = averageCellNumber / sectorWeights[i];
	}

	binaryHistogram = std::vector<bool>(numberOfAngularSectors, false);
	maskedPolarHistogram = std::vector<bool>(numberOfAngularSectors, false);

	leftRadius = rightRadius = 0.0;

	lastDirection = 0;
	std::cout<<"Obstacle OnStart End"<<std::endl;
	return OPROS_SUCCESS;
}
	
ReturnType VFHObstacleAvoidanceComp::onStop()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onReset()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onError()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onRecover()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onDestroy()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onEvent(Event *evt)
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onExecute()
{
	// user code here
#if DEBUG
	cv::waitKey(30);
	//OPRoS::MobileVelocityData vel = this->Avoid(OPRoS::MobilePositionData(0,0,0),OPRoS::MobilePositionData(0,1,0));
	//std::cout<<"selected velocity = "<<vel.x<<","<<vel.theta<<std::endl;
#endif

	return OPROS_SUCCESS;
}
	
ReturnType VFHObstacleAvoidanceComp::onUpdated()
{
	// user code here
	return OPROS_SUCCESS;
}

ReturnType VFHObstacleAvoidanceComp::onPeriodChanged()
{
	// user code here
	return OPROS_SUCCESS;
}


bool VFHObstacleAvoidanceComp::LoadProperty()
{
	if (parameter.FindName ("Weight1") == false) {
		PrintMessage ("ERROR -> Can not found Weight1 parameter\n");
		return false;
	}
	weight1 = atof ((char *)parameter.GetValue("Weight1").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> Weight1 : %d\n", weight1);

	if (parameter.FindName ("Weight2") == false) {
		PrintMessage ("ERROR -> Can not found Weight2 parameter\n");
		return false;
	}
	weight2 = atof ((char *)parameter.GetValue("Weight2").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> Weight2 : %d\n", weight2);

	if (parameter.FindName ("Weight3") == false) {
		PrintMessage ("ERROR -> Can not found Weight3 parameter\n");
		return false;
	}
	weight3 = atof ((char *)parameter.GetValue("Weight3").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> Weight3 : %d\n", weight3);

	if (parameter.FindName ("CellSize") == false) {
		PrintMessage ("ERROR -> Can not found CellSize parameter\n");
		return false;
	}
	std::cout<<parameter.GetValue("CellSize").c_str()<<std::endl;
	cellSize = atof ((char *)parameter.GetValue("CellSize").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> CellSize : %d\n", cellSize);

	if (parameter.FindName ("NumberOfAngularSectors") == false) {
		PrintMessage ("ERROR -> Can not found NumberOfAngularSectors parameter\n");
		return false;
	}
	numberOfAngularSectors = atoi ((char *)parameter.GetValue("NumberOfAngularSectors").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> NumberOfAngularSectors : %d\n", numberOfAngularSectors);

	if (parameter.FindName ("LowerThreshold") == false) {
		PrintMessage ("ERROR -> Can not found LowerThreshold parameter\n");
		return false;
	}
	lowerThreshold = atof ((char *)parameter.GetValue("LowerThreshold").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> LowerThreshold : %d\n", lowerThreshold);

	if (parameter.FindName ("UpperThreshold") == false) {
		PrintMessage ("ERROR -> Can not found UpperThreshold parameter\n");
		return false;
	}
	upperThreshold = atof ((char *)parameter.GetValue("UpperThreshold").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> UpperThreshold : %d\n", upperThreshold);

	if (parameter.FindName ("MinimumNumberForWide") == false) {
		PrintMessage ("ERROR -> Can not found MinimumNumberForWide parameter\n");
		return false;
	}
	minNumberForWide = atoi ((char *)parameter.GetValue("MinimumNumberForWide").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> MinimumNumberForWide : %d\n", minNumberForWide);

	if (parameter.FindName ("RobotRadius") == false) {
		PrintMessage ("ERROR -> Can not found RobotRadius parameter\n");
		return false;
	}
	robotRadius = atof ((char *)parameter.GetValue("RobotRadius").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> RobotRadius : %d\n", robotRadius);

	if (parameter.FindName ("SafeDistance") == false) {
		PrintMessage ("ERROR -> Can not found SafeDistance parameter\n");
		return false;
	}
	safeDistance = atof ((char *)parameter.GetValue("SafeDistance").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> SafeDistance : %d\n", safeDistance);

	if (parameter.FindName ("MaxRadius") == false) {
		PrintMessage ("ERROR -> Can not found MaxRadius parameter\n");
		return false;
	}
	maxRadius = atof ((char *)parameter.GetValue("MaxRadius").c_str());
	PrintMessage ("<VFHObstacleAvoidanceComp Parameter> MaxRadius : %d\n", maxRadius);

	return true;
}

void VFHObstacleAvoidanceComp::MakePolarHistogram(const std::vector<double> &laserData)
{
	std::cout<<"VFHObstacleAvoidanceComp::MakePolarHistogram()"<<std::endl;

	certaintyTable = std::vector<std::vector<double> >(influenceTable.size(), std::vector<double>(influenceTable.size(), 0));

	for (unsigned int i=0; i<sensorCount; ++i) {
		if (laserData[i] >= 0 && laserData[i] <= maxRange) {
			double theta = startAngle + (endAngle - startAngle) / (sensorCount-1) * i + sensorPosition.theta;
			double x = laserData[i] * cos(theta) + sensorPosition.x;
			double y = laserData[i] * sin(theta) + sensorPosition.y;

			int ix = floor(x/cellSize) + (influenceTable.size()-1)/2;
			int iy = floor(y/cellSize) + (influenceTable.size()-1)/2;

			if (ix >= 0 && ix < (int)influenceTable.size() && iy >= 0 && iy < (int)influenceTable.size()) {
				if (influenceTable[ix][iy] > 0) {
					++certaintyTable[ix][iy];
				}
			}
		}
	}

	polarHistogram = std::vector<double>(numberOfAngularSectors, 0);
	activeCellIndices.clear();

	for (unsigned int i=0; i<influenceTable.size(); ++i) {
		for (unsigned int j=0; j<influenceTable.size(); ++j) {
			if (certaintyTable[i][j] > 0) {
				double m = certaintyTable[i][j]*certaintyTable[i][j] * influenceTable[i][j];

				int index = Rad2Index(directions[i][j]);
				int deltaIndex = Rad2Index(enlargementAngle[i][j]-M_PI);
				for (int k=index-deltaIndex; k<=index+deltaIndex; ++k) {
					int l = k - floor((double)k / numberOfAngularSectors) * numberOfAngularSectors;
					polarHistogram[l] = (polarHistogram[l] < m * sectorWeights[l]) ? m * sectorWeights[l] : polarHistogram[l];
				}

				activeCellIndices.push_back(std::pair<unsigned int, unsigned int>(i,j));
			}
		}
	}
#if DEBUG
	double mx = 0;
	std::cout<<std::setprecision(3);
	for (int i=0; i<influenceTable.size(); ++i) {
		for (int j=0; j<influenceTable.size(); ++j) {
			mx = mx < certaintyTable[i][j] ? certaintyTable[i][j] : mx;
			//std::cout<<std::setw(10)<<"("<<i<<","<<j<<")="<<certaintyTable[i][j]<<"\t";
		}
		//std::cout<<std::endl;
	}
//	for (int i=0; i<activeCellIndices.size(); ++i)
//		std::cout<<i<<" = "<<activeCellIndices[i].first<<","<<activeCellIndices[i].second<<std::endl;

	int z = 10;
	cv::Mat im (influenceTable.size()*z, influenceTable.size()*z, CV_8UC3);
	for (int i=0; i<influenceTable.size(); ++i)
		for (int j=0; j<influenceTable.size(); ++j) {
			for (int k=0; k<z; ++k)
				for (int l=0; l<z; ++l)
			im.at<cv::Vec3b>((certaintyTable.size()-1-j)*z+k,z*i+l)[0] = im.at<cv::Vec3b>((certaintyTable.size()-1-j)*z+k,z*i+l)[1] = im.at<cv::Vec3b>((certaintyTable.size()-1-j)*z+k,z*i+l)[2] = 255.* certaintyTable[i][j] / mx;
		}
	//cv::imshow("localmap",im);

	cv::Mat im2 (influenceTable.size()*z, influenceTable.size()*z, CV_8UC3);
		for (int i=0; i<influenceTable.size(); ++i)
			for (int j=0; j<influenceTable.size(); ++j) {
				for (int k=0; k<z; ++k)
					for (int l=0; l<z; ++l)
				im2.at<cv::Vec3b>((certaintyTable.size()-1-j)*z+k,z*i+l)[0] = im2.at<cv::Vec3b>((certaintyTable.size()-1-j)*z+k,z*i+l)[1] = im2.at<cv::Vec3b>((certaintyTable.size()-1-j)*z+k,z*i+l)[2] = 255.* certaintyTable[i][j]*certaintyTable[i][j]*influenceTable[i][j] / mx;
			}
	//cv::imshow("localmap2",im2);


#endif
}

void VFHObstacleAvoidanceComp::MakeMaskedPolarHistogram()
{
	std::cout<<"VFHObstacleAvoidanceComp::MakeMaskedPolarHistogram()"<<std::endl;

	for (unsigned int i=0; i<numberOfAngularSectors; ++i) {
		binaryHistogram[i] = (polarHistogram[i] > upperThreshold) ? true : ((polarHistogram[i] < lowerThreshold) ? false : binaryHistogram[i]);
		binaryHistogram[i] = (Index2Rad(i) < startAngle || Index2Rad(i) > endAngle) ? true : binaryHistogram[i];
	}

	double backTheta = DeltaRad(currentPosition.theta + M_PI, 0);
	double leftBound = M_PI;
	double rightBound = -M_PI;

	double leftDistanceThreshold = (leftRadius + enlargedRobotRadius)*(leftRadius + enlargedRobotRadius);
	double rightDistanceThreshold = (rightRadius + enlargedRobotRadius)*(rightRadius + enlargedRobotRadius);
	double xL = - leftRadius * sin(currentPosition.theta);
	double yL = leftRadius * cos(currentPosition.theta);
	double xR = rightRadius * sin(currentPosition.theta);
	double yR = - rightRadius * cos(currentPosition.theta);
	for (unsigned int i=0; i<activeCellIndices.size(); ++i) {
		double x = cellSize * (activeCellIndices[i].first + (influenceTable.size()-1)/2);
		double y = cellSize * (activeCellIndices[i].second + (influenceTable.size()-1)/2);
		double dTheta =	DeltaRad(directions[activeCellIndices[i].first][activeCellIndices[i].second], currentPosition.theta);
		if ((xL - x)*(xL - x) + (yL - y)*(yL - y) < leftDistanceThreshold) {
			leftBound = (leftBound > dTheta) ? dTheta : leftBound;
		}
		if ((xR - x)*(xR - x) + (yR - y)*(yR - y) < rightDistanceThreshold) {
			rightBound = (rightBound < dTheta) ? dTheta : rightBound;
		}
	}

	for (unsigned int i=0; i<numberOfAngularSectors; ++i) {
		maskedPolarHistogram[i] = !(!binaryHistogram[i] && (DeltaRad(Index2Rad(i),currentPosition.theta) <= leftBound) && (DeltaRad(Index2Rad(i),currentPosition.theta) >= rightBound));
	}
}

int VFHObstacleAvoidanceComp::SelectDirection()
{
	std::cout<<"VFHObstacleAvoidanceComp::SelectDirection()"<<std::endl;

	bordersOfOpennings.clear();

	bool lastState = maskedPolarHistogram.back();
	if (!lastState) {
		bordersOfOpennings.push_back(std::pair<int, int>(0, 0));
	}

	for (unsigned int i=0; i<numberOfAngularSectors; ++i) {
		if (lastState != maskedPolarHistogram[i]) {
			if (lastState) {
				bordersOfOpennings.push_back(std::pair<int, int>(i, 0));
			} else {
				bordersOfOpennings.back().second = i;
			}
			lastState = !lastState;
		}
	}

	if (bordersOfOpennings.size() == 0) {
		return -1;
	}

	if (!maskedPolarHistogram.back()) {
		bordersOfOpennings.front().first = bordersOfOpennings.back().first;
		bordersOfOpennings.resize(bordersOfOpennings.size()-1);
	}

	bordersOfOpennings.front().second += (bordersOfOpennings.front().first > bordersOfOpennings.front().second) ? numberOfAngularSectors : 0;

	unsigned int targetDirection = Rad2Index(DeltaRad(atan2(targetPosition.y-currentPosition.y, targetPosition.x-currentPosition.x),currentPosition.theta));

	std::vector<unsigned int> candidateDirection;
	for (auto x : bordersOfOpennings) {
		unsigned int width = x.second - x.first;

		if (width >= minNumberForWide) {
			candidateDirection.push_back(x.first + minNumberForWide/2);
			candidateDirection.back() -= (candidateDirection.back() >= numberOfAngularSectors) ? numberOfAngularSectors : 0;

			candidateDirection.push_back(x.second + numberOfAngularSectors - 1 - minNumberForWide/2);
			candidateDirection.back() -= (candidateDirection.back() >= numberOfAngularSectors) ? numberOfAngularSectors : 0;

			if ((x.first <= (int)targetDirection && x.second > (int)targetDirection) || (x.first <= (int)targetDirection+(int)numberOfAngularSectors && x.second > (int)targetDirection+(int)numberOfAngularSectors)) {
				candidateDirection.push_back(targetDirection);
			}
		} else {
			candidateDirection.push_back((x.first + x.second - 1) / 2);
		}
	}

	unsigned int robotOrientation = Rad2Index(currentPosition.theta);
	//candidateDirection.push_back(robotOrientation);
	//candidateDirection.push_back(lastDirection);

#if DEBUG
	std::cout<<"ok";
	for (int i=0; i<polarHistogram.size(); ++i)
		std::cout<<std::setw(10)<<RAD2DEG(Index2Rad(i))<<",";
	std::cout<<std::endl;
	for (int i=0; i<polarHistogram.size(); ++i)
		std::cout<<std::setw(10)<<polarHistogram[i]<<",";
	std::cout<<std::endl;
	std::cout<<"ok";
	for (int i=0; i<bordersOfOpennings.size(); ++i)
		std::cout<<"openning "<<i<<" = "<<std::setw(10)<<RAD2DEG(Index2Rad(bordersOfOpennings[i].first))<<"\t"<<RAD2DEG(Index2Rad(bordersOfOpennings[i].second))<<std::endl;
	std::cout<<"ok";
	for (int i=0; i<candidateDirection.size(); ++i)
		std::cout<<"candidate "<<i<<" = "<<std::setw(10)<<RAD2DEG(Index2Rad(candidateDirection[i]))<<std::endl;

	std::cout<<"target = "<<RAD2DEG(Index2Rad(targetDirection))<<std::endl;
#endif

	double bestCost = std::numeric_limits<double>::max();
	unsigned int bestDirection = 0;
	for (unsigned int x : candidateDirection) {
		double cost = weight1 * DeltaIndex(x, targetDirection) + weight2 * DeltaIndex(x, robotOrientation) + weight3 * DeltaIndex(x, lastDirection);
		if (cost < bestCost) {
			bestCost = cost;
			bestDirection = x;
		}
	}

	lastDirection = bestDirection;
	return bestDirection;
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
	return new VFHObstacleAvoidanceComp();
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
	return new VFHObstacleAvoidanceComp();
}

void releaseComponent(Component *com)
{
	delete com;
}
#endif
#endif

